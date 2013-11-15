#ifndef SCREEN_H_
#define SCREEN_H_

#include "Controller.h"
#include "View.h"

class Screen {
public:
  Screen(Camera &camera, GLFWwindow* window);
  ~Screen();

  void input();
  void update();
  void render();
private:
  GLFWwindow* window_;

  Camera &camera_;

  View view_;
  Controller controller_;
};

#endif