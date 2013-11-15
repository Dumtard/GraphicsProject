#include "Camera.h"

#include <iostream>

Camera::Camera() {
  position_ = glm::vec3(0, 5, 0);
  direction_ = glm::vec3(0, 0, 1);
  upDirection_ = glm::vec3(0, 1, 0);
  rightDirection_ = glm::cross(direction_, upDirection_);

  view_ = glm::lookAt(position_, position_ + direction_, upDirection_);
}

Camera::~Camera() {
}

void Camera::update() {
  view_ = glm::lookAt(position_, position_ + direction_, upDirection_);
}

glm::mat4 Camera::getView() {
  return view_;
}

glm::vec3 Camera::getPosition() {
  return position_;
}

void Camera::setPosition(glm::vec3 position) {
  position_ = position;
  // std::cout << position.x << ", " << position.y << ", " 
            // << position.z << std::endl;
}

glm::vec3 Camera::getDirection() {
  return direction_;
}

void Camera::setDirection(glm::vec3 direction) {
  direction_ = direction;
}

glm::vec3 Camera::getUpDirection() {
  return upDirection_;
}

void Camera::setUpDirection(glm::vec3 upDirection) {
  upDirection_ = upDirection;
}

glm::vec3 Camera::getRightDirection() {
  return rightDirection_;
}

void Camera::setRightDirection(glm::vec3 rightDirection) {
  rightDirection_ = rightDirection;
}