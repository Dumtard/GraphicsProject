#include "Screen.h"

#include <iostream>

Screen::Screen(Camera &camera, GLFWwindow* window) :
               window_(window), camera_(camera), view_(camera),
               controller_(camera, window) {
}

Screen::~Screen() {

}

void Screen::input() {
  controller_.input();
}

void Screen::update() {
  camera_.update();
  view_.update();
}

void Screen::render() {
  view_.render();
}