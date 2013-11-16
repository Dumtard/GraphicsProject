#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <iostream>

#include "Camera.h"
#include "Terrain.h"

class Controller {
public:
  Controller(Camera &camera, GLFWwindow* window, Terrain &terrain);
  ~Controller();

  void update();
  void input();
  
private:
  GLFWwindow *window_;

  Camera &camera_;
  Terrain &terrain_;
};

#endif