#ifndef SCREEN_H_
#define SCREEN_H_

#include "Controller.h"
#include "Terrain.h"
#include "Tree.h"
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

  Terrain terrain_;
  std::vector<Tree> trees_;

  View view_;
  Controller controller_;

  std::mt19937 rng_;
};

#endif