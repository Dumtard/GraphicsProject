#ifndef SHADER_H_
#define SHADER_H_

#include <fstream>
#include <iostream>
#include <vector>

#include <GL/glew.h>

namespace Helper {

GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);

};

#endif