#version 330 core

// Values that stay constant for the whole mesh.
uniform mat4 MVP;
uniform mat4 M;
uniform mat4 V;

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 vertexNormal;
layout(location = 2) in vec2 vertexUV;

out vec3 normal;
out vec2 UV;

out vec3 Position_worldspace;

out vec3 lightDir;
out vec3 eyeDir;

void main() {
  vec3 lightPos = vec3(50, 50, 50);

  UV = vertexUV;

  gl_Position =  MVP * vec4(vertexPosition_modelspace, 1);

  Position_worldspace = (M * vec4(vertexPosition_modelspace,1)).xyz;

  vec3 vertexPosition_cameraspace = ( V * M * vec4(vertexPosition_modelspace,1)).xyz;
  eyeDir = vec3(0,0,0) - vertexPosition_cameraspace;

  vec3 LightPosition = ( V * vec4(lightPos, 1)).xyz;
  lightDir = LightPosition + eyeDir;

  normal = normalize(( V * M * vec4(vertexNormal,0)).xyz); // Only correct if ModelMatrix does not scale the model ! Use its inverse transpose if not.
}