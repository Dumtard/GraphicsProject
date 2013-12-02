#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

namespace Helper {

// Load a .DDS file using GLFW's own loader
GLuint loadDDS(const char * imagepath);

};

#endif