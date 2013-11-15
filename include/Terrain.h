#ifndef TERRAIN_H_
#define TERRAIN_H_

#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include "SimplexNoise.h"
#include "VboIndexer.h"

struct Face {
  glm::vec3 vertices[3];
  glm::vec3 normals[3];
};

class Terrain {
public:
  Terrain();
  ~Terrain();

  void createCube();
  void render(GLuint &programID);

private:
  void generateFaces(std::vector<std::vector<glm::vec3>> &tempVertices,
                     std::vector<glm::vec3> &vertices2);
  void generateNormals();

  GLuint VertexArrayID;
  GLuint vertexbuffer;
  GLuint normalbuffer;
  GLuint elementbuffer;

  std::vector<Face> faces;
  std::vector<unsigned int> indices;
  std::vector<glm::vec3> vertices;
  std::vector<glm::vec3> normals;

  //REMOVE
  // std::vector<glm::vec3> vertices2;
};

#endif