#ifndef TERRAIN_H_
#define TERRAIN_H_

#include <ctime>
#include <random>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include "SimplexNoise.h"
#include "VboIndexer.h"

class Terrain {
public:
  Terrain();
  ~Terrain();

  void generateTerrain();
  void render(GLuint &programID);

  float getHeight(const glm::vec3 &position);
  int getWidth();
  int getLength();

private:
  void generateFaces(std::vector<std::vector<glm::vec3>> &tempVertices,
                     std::vector<glm::vec3> &vertices2);
  void generateNormals();

  unsigned int currentSeed_;

  int width_;
  int length_;

  GLuint VertexArrayID;
  GLuint vertexbuffer;
  GLuint normalbuffer;
  GLuint elementbuffer;

  std::vector<unsigned int> indices;
  std::vector<glm::vec3> vertices;
  std::vector<glm::vec3> normals;

  //REMOVE
  // std::vector<glm::vec3> vertices2;
};

#endif