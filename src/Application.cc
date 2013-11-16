#include "Application.h"

Application::~Application() {
  glfwDestroyWindow(window_);
  glfwTerminate();
}

void Application::initialize() {

  // windowWidth = 1366;
  // windowHeight = 768;

  windowWidth = 800;
  windowHeight = 600;

  // Initialize the library
  if (!glfwInit())
    return;

  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  glfwWindowHint(GLFW_SAMPLES, 16);
  // glfwWindowHint(GLFW_DECORATED, GL_FALSE);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

  // Create a windowed mode window and its OpenGL context
  window_ = glfwCreateWindow(windowWidth, windowHeight,
                            "Haunted Forest", NULL, NULL);
  if (!window_) {
    glfwTerminate();
    return;
  }
  glfwMakeContextCurrent(window_);

  // Initialize GLEW
  glewExperimental = true; // Needed for core profile
  if (glewInit() != GLEW_OK) {
    std::cout << "Failed to initialize GLEW" << std::endl;
    return;
  }

  // Enable depth test
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
  // Accept fragment if it closer to the camera than the former one
  glDepthFunc(GL_LESS);

  const GLFWvidmode* vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());

  glfwSetWindowPos(window_, (vidmode->width - windowWidth) / 2,
                           (vidmode->height - windowHeight) / 2);

  screen_ = std::unique_ptr<Screen>(new Screen(camera_, window_));

  for (double i = 0; i < 100; i+=0.1) {
    for (double j = 0; j < 100; j+=0.1) {
      // std::cout << j << ", " << octave_noise_3d(3, 0.9, 0.25, i, j, 0) << std::endl; 
      // << ", " << i << std::endl;
      // octave_noise_3d(3, 0.9, 0.25, i, j, 0);
    }
  }
}

GLFWwindow* Application::getWindow() {
  return window_;
}

void Application::run() {
  while (!glfwWindowShouldClose(window_)) {
    input();
    update();
    render();
    glfwPollEvents();
  }
}

void Application::input() {
  if (glfwGetKey(window_, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window_, GL_TRUE);
  }

  screen_->input();
}

void Application::update() {
  screen_->update();
}

void Application::render() {
  // Clear the screen
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(1, 1, 1, 1);

  screen_->render();

  glfwSwapBuffers(window_);
}