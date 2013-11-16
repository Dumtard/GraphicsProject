#include "Shader.h"

namespace Helper {

GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path) {

  // Create the shaders
  GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
  GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

  // Read the Vertex Shader code from the file
  std::string vertexShaderCode;
  std::ifstream vertexShaderStream(vertex_file_path, std::ios::in);
  
  if (vertexShaderStream.is_open()) {
    std::string line = "";
    while (getline(vertexShaderStream, line)) {
      vertexShaderCode += "\n" + line;
    }
    vertexShaderStream.close();
  } else {
    std::cout << "Impossible to open " << vertex_file_path << ". Are you in the right directory ? Don't forget to read the FAQ !" << std::endl;
    getchar();
    return 0;
  }

  // Read the Fragment Shader code from the file
  std::string fragmentShaderCode;
  std::ifstream fragmentShaderStream(fragment_file_path, std::ios::in);
  if (fragmentShaderStream.is_open()) {
    std::string line = "";
    while (getline(fragmentShaderStream, line))
      fragmentShaderCode += "\n" + line;
    fragmentShaderStream.close();
  }

  GLint Result = GL_FALSE;
  int InfoLogLength;

  // Compile Vertex Shader
  std::cout << "Compiling shader : " <<  vertex_file_path << std::endl;
  char const * VertexSourcePointer = vertexShaderCode.c_str();
  glShaderSource(vertexShaderID, 1, &VertexSourcePointer , NULL);
  glCompileShader(vertexShaderID);

  // Check Vertex Shader
  glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &Result);
  glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
  if (InfoLogLength > 0) {
    std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
    glGetShaderInfoLog(vertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
    std::cout << &VertexShaderErrorMessage[0] << std::endl;
  }

  // Compile Fragment Shader
  std::cout << "Compiling shader : " <<  fragment_file_path << std::endl;
  char const * fragmentSourcePointer = fragmentShaderCode.c_str();
  glShaderSource(fragmentShaderID, 1, &fragmentSourcePointer , NULL);
  glCompileShader(fragmentShaderID);

  // Check Fragment Shader
  glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &Result);
  glGetShaderiv(fragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);

  if (InfoLogLength > 0) {
    std::vector<char> FragmentShaderErrorMessage(InfoLogLength+1);
    glGetShaderInfoLog(fragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
    std::cout << &FragmentShaderErrorMessage[0] << std::endl;
  }

  // Link the program
  std::cout << "Linking program\n" << std::endl;
  GLuint ProgramID = glCreateProgram();
  glAttachShader(ProgramID, vertexShaderID);
  glAttachShader(ProgramID, fragmentShaderID);
  glLinkProgram(ProgramID);

  // Check the program
  glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
  glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);

  if (InfoLogLength > 0) {
    std::vector<char> ProgramErrorMessage(InfoLogLength+1);
    glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
    std::cout << &ProgramErrorMessage[0] << std::endl;
  }

  glDeleteShader(vertexShaderID);
  glDeleteShader(fragmentShaderID);

  return ProgramID;
}

};