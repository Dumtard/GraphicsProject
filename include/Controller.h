#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Camera.h"

class Controller {
public:
  Controller(Camera &camera, GLFWwindow* window);
  ~Controller();

  void update();
  void input();
  
private:
  GLFWwindow *window_;

  Camera &camera_;
};

#endif