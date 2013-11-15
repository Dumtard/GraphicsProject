#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <iostream>
#include <memory>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "SimplexNoise.h"
#include "Camera.h"
#include "View.h"
#include "Screen.h"

class Application {
public:
  static Application& getInstance() {
    static Application instance;
    return instance;
  }
  ~Application();

  void run();

  GLFWwindow* getWindow();

private:
  Application() {
    initialize();
  };

  int windowWidth, windowHeight;

  void initialize();

  void input();
  void update();
  void render();

  GLFWwindow* window_;

  std::unique_ptr<Screen> screen_;

  Camera camera_;
};

#endif