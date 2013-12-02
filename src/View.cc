#include "View.h"

View::View(Camera &camera, Terrain &terrain, std::vector<Tree> &trees) :
           camera_(camera), terrain_(terrain), trees_(trees) {
  projection = glm::perspective(45.0f, 16.0f / 9.0f, 0.1f, 1000.0f);

  terrainProgramID_ = Helper::LoadShaders("shaders/TerrainVertex.glsl",
                                          "shaders/TerrainFragment.glsl");
  treeProgramID_ = Helper::LoadShaders("shaders/TreeVertex.glsl",
                                       "shaders/TreeFragment.glsl");

  matrixID = glGetUniformLocation(terrainProgramID_, "MVP");
  mID = glGetUniformLocation(terrainProgramID_, "M");
  vID = glGetUniformLocation(terrainProgramID_, "V");
}

View::~View() {
}

glm::mat4& View::getProjection() {
  return projection;
}

void View::update() {
  MVP = getProjection() * camera_.getView() * glm::mat4(1.0f);
  glUseProgram(terrainProgramID_);
  glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);
  glUniformMatrix4fv(mID, 1, GL_FALSE, &glm::mat4(1.0f)[0][0]);
  glUniformMatrix4fv(vID, 1, GL_FALSE, &camera_.getView()[0][0]);
}

void View::render() {
  terrain_.render(terrainProgramID_);

  for (auto& tree : trees_) {
    tree.render(terrainProgramID_, getProjection(), camera_.getView());
  }
}