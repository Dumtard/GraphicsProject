#include "Controller.h"

Controller::Controller(Camera &camera, GLFWwindow* window, Terrain &terrain) :
                       window_(window), camera_(camera), terrain_(terrain) {

}

Controller::~Controller() {

}

void Controller::update() {
  float height = terrain_.getHeight(camera_.getPosition());
  camera_.setPosition(glm::vec3(camera_.getPosition().x,
                                height + 1,
                                camera_.getPosition().z));

  if (camera_.getPosition().x >= terrain_.getWidth()-1) {
    camera_.setPosition(glm::vec3(terrain_.getWidth()-1,
                                  camera_.getPosition().y,
                                  camera_.getPosition().z));
  }
  if (camera_.getPosition().x <= 0) {
    camera_.setPosition(glm::vec3(0,
                                  camera_.getPosition().y,
                                  camera_.getPosition().z));
  }
  if (camera_.getPosition().z >= terrain_.getLength()-1) {
    camera_.setPosition(glm::vec3(camera_.getPosition().x,
                                  camera_.getPosition().y,
                                  terrain_.getLength()-1));
  }
  if (camera_.getPosition().z <= 0) {
    camera_.setPosition(glm::vec3(camera_.getPosition().x,
                                  camera_.getPosition().y,
                                  0));
  }
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
  if (glfwGetKey(window_, GLFW_KEY_R) == GLFW_PRESS) {
    terrain_.generateTerrain();
  }

  // Mouse rotation
  double x, y = 0;
  int windowWidth, windowHeight = 0;
  glfwGetWindowSize(window_, &windowWidth, &windowHeight);

  glfwGetCursorPos(window_, &x, &y);
  glfwSetCursorPos(window_, windowWidth/2, windowHeight/2);

  camera_.setX(camera_.getX() + (x-(windowWidth/2))/360);
  camera_.setY(camera_.getY() + (y-(windowHeight/2))/360);

  camera_.setDirection(glm::vec3(cos(camera_.getX()),
                                 cos(camera_.getY()),
                                 sin(camera_.getX())));
}