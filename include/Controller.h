#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <iostream>
#include <vector>

#include "Camera.h"
#include "Terrain.h"
#include "Tree.h"

class Controller {
public:
  Controller(Camera &camera, GLFWwindow* window, Terrain &terrain,
             std::vector<Tree> &trees);
  ~Controller();

  void update();
  void input();
  
private:
  GLFWwindow *window_;

  Camera &camera_;
  Terrain &terrain_;
  std::vector<Tree> &trees_;
};

#endif