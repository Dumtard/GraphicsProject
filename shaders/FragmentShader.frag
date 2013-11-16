#version 330 core

in vec3 position;
in vec3 normal;

out vec3 color;

void main() {
  // Output color = red
  vec3 lightPos = vec3(250, 50, 250);

  vec3 L = normalize(lightPos);

  vec3 Iamb = vec3(0.1, 0.1, 0.1);

  vec3 Idiff = vec3(0.8, 0.8, 0.8) * max(dot(normalize(normal),L), 0.0);

  float z = gl_FragCoord.z / gl_FragCoord.w;

  if (position.y < 0) color = vec3(0, 0, 1);
  else if (position.y >= 0 && position.y <= 5)
    color = vec3(0, 1, 0) * Iamb + Idiff;
  //color *= (z/10);

}