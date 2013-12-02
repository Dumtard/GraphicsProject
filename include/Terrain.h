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
#include "Texture.h"

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
  void generateFaces(std::vector<std::vector<glm::vec3>> &tempVertices);
  void generateNormals();

  unsigned int currentSeed_;

  int width_;
  int length_;

  GLuint VertexArrayID;
  GLuint vertexbuffer;
  GLuint normalbuffer;
  GLuint uvbuffer;
  GLuint elementbuffer;

  GLuint texture_;
  GLuint textureID_;

  std::vector<unsigned int> indices;
  std::vector<glm::vec3> vertices;
  std::vector<glm::vec3> normals;
  std::vector<glm::vec2> uvs;
};

#endif