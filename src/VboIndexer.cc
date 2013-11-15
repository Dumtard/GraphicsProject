#include <vector>
#include <map>
#include <iostream>

#include <glm/glm.hpp>

#include "VboIndexer.h"

#include <string.h> // for memcmp

struct PackedVertex{
  glm::vec3 position;
  bool operator<(const PackedVertex that) const{
    return memcmp((void*)this, (void*)&that, sizeof(PackedVertex))>0;
  };
};

bool getSimilarVertexIndex_fast( 
  PackedVertex & packed, 
  std::map<PackedVertex,unsigned int> & VertexToOutIndex,
  unsigned int & result
){
  std::map<PackedVertex,unsigned int>::iterator it = VertexToOutIndex.find(packed);
  if ( it == VertexToOutIndex.end() ){
    return false;
  }else{
    result = it->second;
    return true;
  }
}

void indexVBO(
  std::vector<glm::vec3> & in_vertices,

  std::vector<unsigned int> & out_indices,
  std::vector<glm::vec3> & out_vertices
){
  std::map<PackedVertex,unsigned int> VertexToOutIndex;

  // For each input vertex
  for (unsigned int i = 0; i < in_vertices.size(); i++) {

    PackedVertex packed = {in_vertices[i]};

    // Try to find a similar vertex in out_XXXX
    unsigned int index;
    bool found = getSimilarVertexIndex_fast(packed, VertexToOutIndex, index);

    if (found){ // A similar vertex is already in the VBO, use it instead !
      out_indices.push_back(index);
    } else { // If not, it needs to be added in the output data.
      out_vertices.push_back(in_vertices[i]);
      unsigned int newindex = (unsigned int)out_vertices.size() - 1;
      out_indices.push_back(newindex);
      VertexToOutIndex[packed] = newindex;
    }
  }
}
