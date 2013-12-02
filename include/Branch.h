#ifndef BRANCH_H_
#define BRANCH_H_

#include <vector>
#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Branch {
public:
  Branch();
  ~Branch();

  glm::mat4& getModelMatrix();
  void setModelMatrix(glm::mat4 matrix);

  void render();

private:
  GLuint VertexArrayID_;
  GLuint vertexbuffer_;
  GLuint normalbuffer_;
  GLuint uvbuffer_;
  GLuint elementbuffer_;

  GLuint matrixID_;
  glm::mat4 model_;

  std::vector<unsigned int> indices_;
  std::vector<glm::vec3> vertices_;
  std::vector<glm::vec2> uvs_;
  std::vector<glm::vec3> normals_;
};

#endif