#version 330 core

in vec3 normal;
in vec2 UV;

in vec3 Position_worldspace;

in vec3 lightDir;
in vec3 eyeDir;

uniform sampler2D textureSampler;

out vec3 color;

void main() {
  vec3 LightColor = vec3(1,1,1);
  float LightPower = 5000.0f;
  
  // Material properties
  vec3 MaterialDiffuseColor = texture2D( textureSampler, UV ).rgb;
  vec3 MaterialAmbientColor = vec3(0.1,0.1,0.1) * MaterialDiffuseColor;

  float distance = length( vec3(50, 50, 50) - Position_worldspace );

  vec3 n = normalize( normal );
  vec3 l = normalize( lightDir );
  float cosTheta = clamp( dot( n,l ), 0,1 );
  
  color = 
    MaterialDiffuseColor;
}