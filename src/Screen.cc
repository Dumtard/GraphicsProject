#include "Screen.h"

#include <iostream>

Screen::Screen(Camera &camera, GLFWwindow* window) :
               window_(window), camera_(camera), view_(camera, terrain_),
               controller_(camera, window, terrain_) {

terrain_.generateTerrain();

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