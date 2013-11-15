#include "Controller.h"

Controller::Controller(Camera &camera, GLFWwindow* window) :
                       window_(window), camera_(camera) {

}

Controller::~Controller() {

}

void Controller::update() {

}

void Controller::input() {
  if (glfwGetKey(window_, GLFW_KEY_UP) == GLFW_PRESS) {
    camera_.setPosition(camera_.getPosition() + camera_.getDirection());
  }
  if (glfwGetKey(window_, GLFW_KEY_DOWN) == GLFW_PRESS) {
    camera_.setPosition(camera_.getPosition() - camera_.getDirection());
  }
  if (glfwGetKey(window_, GLFW_KEY_LEFT) == GLFW_PRESS) {
    camera_.setPosition(camera_.getPosition() - camera_.getRightDirection());
  }
  if (glfwGetKey(window_, GLFW_KEY_RIGHT) == GLFW_PRESS) {
    camera_.setPosition(camera_.getPosition() + camera_.getRightDirection());
  }
}