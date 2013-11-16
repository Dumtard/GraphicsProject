#ifndef CAMERA_H_
#define CAMERA_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Camera {
public:
  Camera();
  ~Camera();

  void update();

  glm::mat4 getView();

  glm::vec3 getPosition();
  void setPosition(glm::vec3 position);
  glm::vec3 getDirection();
  void setDirection(glm::vec3 lookAt);
  glm::vec3 getUpDirection();
  void setUpDirection(glm::vec3 upDirection);
  glm::vec3 getRightDirection();
  void setRightDirection(glm::vec3 rightDirection);
  float getX();
  void setX(float x); 
  float getY();
  void setY(float y);   

private:
  glm::vec3 position_;
  glm::vec3 direction_;
  glm::vec3 upDirection_;
  glm::vec3 rightDirection_;

  GLuint MatrixID_;
  glm::mat4 view_;

  float x_, y_;
};

#endif