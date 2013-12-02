#include "Screen.h"

Screen::Screen(Camera &camera, GLFWwindow* window) :
               window_(window), camera_(camera),
               view_(camera, terrain_, trees_),
               controller_(camera, window, terrain_, trees_) {

  terrain_.generateTerrain();

  rng_.seed(time(0));

  for (unsigned int i = 0; i < 100; i++) {
    Tree tree(rng_);
    tree.generateTree(terrain_);
    trees_.push_back(tree);
  }
}

Screen::~Screen() {

}

void Screen::input() {
  controller_.input();
}

void Screen::update() {
  controller_.update();
  camera_.update();
  view_.update();
}

void Screen::render() {
  view_.render();
}