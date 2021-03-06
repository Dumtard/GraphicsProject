#ifndef VBOINDEXER_HPP
#define VBOINDEXER_HPP

namespace Helper {

void indexVBO(
  std::vector<glm::vec3> & in_vertices,

  std::vector<unsigned int> & out_indices,
  std::vector<glm::vec3> & out_vertices
);

};

#endif