#version 330 core

// Values that stay constant for the whole mesh.
uniform mat4 MVP;

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 vertexNormal;

out vec3 normal;

out vec3 position;

void main() {
  // Output position of the vertex, in clip space : MVP * position
  gl_Position =  MVP * vec4(vertexPosition_modelspace, 1);

  normal = normalize(vertexNormal);

  gl_FrontColor = vec4(0, 1, 0, 1);

  position = vertexPosition_modelspace;
}