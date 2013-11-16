#include "Terrain.h"

#include <iostream>

Terrain::Terrain() {
  currentSeed_ = 0;
  width_ = length_ = 500;
}

Terrain::~Terrain() {
  glDeleteBuffers(1, &vertexbuffer);
  glDeleteBuffers(1, &normalbuffer);
  glDeleteVertexArrays(1, &VertexArrayID);
}

int Terrain::getWidth() {
  return width_;
}

int Terrain::getLength() {
  return length_;
}

float Terrain::getHeight(const glm::vec3 &position) {
  float height = scaled_octave_noise_3d(3, 0.9, 0.005, -2, 5,
                                        position.x, currentSeed_, position.z);
  return height;
}

void Terrain::generateTerrain() {
  indices.clear();
  vertices.clear();
  normals.clear();

  std::mt19937 rng;
  rng.seed(time(0));
  std::uniform_int_distribution<uint32_t> uint_dist(0, 1000);
  currentSeed_ = uint_dist(rng);

  //Generate the terrain
  std::cout << "Seed: " << currentSeed_ << std::endl;
  std::cout << "Generating heights...";

  std::vector<std::vector<glm::vec3>> tempVertices;
  std::vector<glm::vec3> vertices2;

  for (double i = 0; i < length_; i+=1) {
    std::vector<glm::vec3> tempVertices2;
    for (double j = 0; j < width_; j+=1) {
      glm::vec3 vertex = glm::vec3(i, scaled_octave_noise_3d(
                                      3, 0.9, 0.005, -2, 5, i, currentSeed_, j),
                                   j);
      tempVertices2.push_back(vertex);
    }
    tempVertices.push_back(tempVertices2);
  }
  std::cout << "Done" << std::endl << "Triangulating...";
  generateFaces(tempVertices, vertices2);
  std::cout << "Done" << std::endl << "Indexing...";
  indexVBO(vertices2, indices, vertices);
  std::cout << "Done" << std::endl << "Generating Normals...";
  generateNormals();
  std::cout << "Done" << std::endl;

  glGenVertexArrays(1, &VertexArrayID);
  glBindVertexArray(VertexArrayID);

  glGenBuffers(1, &vertexbuffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3),
               &vertices[0], GL_STATIC_DRAW);
  glVertexAttribPointer(0,
                        3,
                        GL_FLOAT,
                        GL_FALSE,
                        0,
                        (void*)0);

  glGenBuffers(1, &normalbuffer);
  glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
  glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3),
               &normals[0], GL_STATIC_DRAW);
  glVertexAttribPointer(1,
                        3,
                        GL_FLOAT,
                        GL_FALSE,
                        0,
                        (void*)0);

  glGenBuffers(1, &elementbuffer);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0] , GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);

  glBindVertexArray(0);
}

void Terrain::generateFaces(std::vector<std::vector<glm::vec3>> &tempVertices,
                            std::vector<glm::vec3> &vertices2) {
  for (unsigned int i = 0; i < tempVertices.size(); i++) {
    for (unsigned int j = 0; j < tempVertices[i].size(); j++) {
      if (j == 0 && i < tempVertices.size() - 1) {
        vertices2.push_back(tempVertices[i][j]);
        vertices2.push_back(tempVertices[i][j+1]);
        vertices2.push_back(tempVertices[i+1][j]);
      } else if (j == tempVertices[i].size() - 1 &&
                 i < tempVertices.size() - 1) {
        vertices2.push_back(tempVertices[i][j]);
        vertices2.push_back(tempVertices[i+1][j]);
        vertices2.push_back(tempVertices[i+1][j-1]);
      } else if (i < tempVertices.size() - 1) {
        vertices2.push_back(tempVertices[i][j]);
        vertices2.push_back(tempVertices[i][j+1]);
        vertices2.push_back(tempVertices[i+1][j]);

        vertices2.push_back(tempVertices[i][j]);
        vertices2.push_back(tempVertices[i+1][j]);
        vertices2.push_back(tempVertices[i+1][j-1]);
      }
    }
  }
}

void Terrain::generateNormals() {
  for (unsigned int i = 0; i < vertices.size(); i++) {
    normals.push_back(glm::vec3(0, 0, 0));
  }

  for (unsigned int i = 0; i < indices.size(); i+=3) {
    // std::cout << indices.size() << std::endl;
    //cross these
    glm::vec3 normal;
    normal = glm::cross(vertices[indices[i+1]] - vertices[indices[i+2]],
                        vertices[indices[i+1]] - vertices[indices[i]]);

    normals[indices[i]] += normal;
    normals[indices[i+1]] += normal;
    normals[indices[i+2]] += normal;
  }

  for (unsigned int i = 0; i < normals.size(); i++) {
    normals[i] = glm::normalize(normals[i]);
  }
}

void Terrain::render(GLuint &programID) {
  glUseProgram(programID);

  glBindVertexArray(VertexArrayID);
  // glDrawArrays(GL_TRIANGLES, 0,  vertices2.size());
  glDrawElements(
      GL_TRIANGLES,      // mode
      indices.size(),    // count
      GL_UNSIGNED_INT,   // type
      (void*)0           // element array buffer offset
    );

  glBindVertexArray(0);
}