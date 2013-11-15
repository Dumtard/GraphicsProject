#ifndef VIEW_H_
#define VIEW_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Shader.h"
#include "Camera.h"
#include "Terrain.h"

class View {
public:
  View(Camera &camera);
  ~View();

  glm::mat4 getProjection();

  void update();
  void render();

private:
  Camera &camera_;
  Terrain terrain_;

  GLuint programID;

  GLuint matrixID;

  glm::mat4 projection;

  glm::mat4 MVP;
};

#endif