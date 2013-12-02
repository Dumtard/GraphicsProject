#ifndef TREE_H_
#define TREE_H_

#include <iostream>
#include <vector>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Branch.h"
#include "Terrain.h"

class Tree {
public:
  Tree(std::mt19937 &rng);
  ~Tree();

  void generateTree(Terrain &terrain);

  void setPosition(glm::vec3 position);

  void render(GLuint programID, glm::mat4 &projection, glm::mat4 &view);

private:
  std::string string_;
  std::mt19937 &rng_;

  GLuint matrixID_;
  GLuint mID_;
  GLuint vID_;

  glm::mat4 model_;
  glm::mat4 MVP_;

  GLuint texture_;
  GLuint textureID_;

  glm::vec3 position_;

  Branch branch;
  std::vector<Branch> branches_;
};

#endif
