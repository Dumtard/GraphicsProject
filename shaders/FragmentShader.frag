#version 330 core

in vec3 position;
in vec3 normal;

// Ouput data
out vec3 color;

void main() {
  // Output color = red
  vec3 lightPos = vec3(250, 50, 250);

  vec3 L = normalize(lightPos - position);   
  vec3 E = normalize(-position);
  vec3 R = normalize(-reflect(L,normal));

  vec3 Idiff = vec3(1, 1, 1) * max(dot(normal,L), 0.0);
  Idiff = clamp(Idiff, 0.0, 1.0);  


  if (position.y < 0) color = vec3(0, 0, 1) * Idiff;
  else if (position.y >= 0 && position.y <= 5) color = vec3(0, 1, 0) * Idiff;

}