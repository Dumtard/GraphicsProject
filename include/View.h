#ifndef VIEW_H_
#define VIEW_H_

#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Shader.h"
#include "Camera.h"
#include "Terrain.h"
#include "Tree.h"

class View {
public:
  View(Camera &camera, Terrain &terrain, std::vector<Tree> &trees);
  ~View();

  glm::mat4& getProjection();

  void update();
  void render();

private:
  Camera &camera_;
  Terrain &terrain_;
  std::vector<Tree> &trees_;

  GLuint terrainProgramID_;
  GLuint treeProgramID_;

  GLuint matrixID;
  GLuint mID;
  GLuint vID;

  glm::mat4 projection;

  glm::mat4 MVP;
};

#endif