#include "View.h"

#include <iostream>

View::View(Camera &camera, Terrain &terrain) : camera_(camera),
           terrain_(terrain) {
  projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 1000.0f);

  programID = Helper::LoadShaders("shaders/VertexShader.vert",
                          "shaders/FragmentShader.frag");

  matrixID = glGetUniformLocation(programID, "MVP");
}

View::~View() {
}

glm::mat4 View::getProjection() {
  return projection;
}

void View::update() {
  MVP = projection * camera_.getView() * glm::mat4(1.0f);
  glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);
}

void View::render() {
  // Use our shader
  glUseProgram(programID);

  terrain_.render(programID);
}