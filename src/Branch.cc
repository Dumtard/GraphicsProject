#include "Branch.h"

Branch::Branch() {

  vertices_ = {
    glm::vec3(0.000000, -1.000000, 0.000000),
    glm::vec3(0.000000, 1.000000, 0.000000),
    glm::vec3(0.000000, -1.000000, -1.000000),
    glm::vec3(0.000000, 1.000000, -1.000000),
    glm::vec3(0.195090, -1.000000, -0.980785),
    glm::vec3(0.195090, 1.000000, -0.980785),
    glm::vec3(0.382683, -1.000000, -0.923880),
    glm::vec3(0.382683, 1.000000, -0.923880),
    glm::vec3(0.555570, -1.000000, -0.831470),
    glm::vec3(0.555570, 1.000000, -0.831470),
    glm::vec3(0.707107, -1.000000, -0.707107),
    glm::vec3(0.707107, 1.000000, -0.707107),
    glm::vec3(0.831470, -1.000000, -0.555570),
    glm::vec3(0.831470, 1.000000, -0.555570),
    glm::vec3(0.923880, -1.000000, -0.382683),
    glm::vec3(0.923880, 1.000000, -0.382683),
    glm::vec3(0.980785, -1.000000, -0.195090),
    glm::vec3(0.980785, 1.000000, -0.195090),
    glm::vec3(1.000000, -1.000000, -0.000000),
    glm::vec3(1.000000, 1.000000, -0.000000),
    glm::vec3(0.980785, -1.000000, 0.195090),
    glm::vec3(0.980785, 1.000000, 0.195090),
    glm::vec3(0.923880, -1.000000, 0.382683),
    glm::vec3(0.923880, 1.000000, 0.382683),
    glm::vec3(0.831470, -1.000000, 0.555570),
    glm::vec3(0.831470, 1.000000, 0.555570),
    glm::vec3(0.707107, -1.000000, 0.707107),
    glm::vec3(0.707107, 1.000000, 0.707107),
    glm::vec3(0.555570, -1.000000, 0.831470),
    glm::vec3(0.555570, 1.000000, 0.831470),
    glm::vec3(0.382683, -1.000000, 0.923880),
    glm::vec3(0.382683, 1.000000, 0.923880),
    glm::vec3(0.195090, -1.000000, 0.980785),
    glm::vec3(0.195090, 1.000000, 0.980785),
    glm::vec3(-0.000000, -1.000000, 1.000000),
    glm::vec3(-0.000000, 1.000000, 1.000000),
    glm::vec3(-0.195091, -1.000000, 0.980785),
    glm::vec3(-0.195091, 1.000000, 0.980785),
    glm::vec3(-0.382684, -1.000000, 0.923879),
    glm::vec3(-0.382684, 1.000000, 0.923879),
    glm::vec3(-0.555571, -1.000000, 0.831469),
    glm::vec3(-0.555571, 1.000000, 0.831469),
    glm::vec3(-0.707107, -1.000000, 0.707106),
    glm::vec3(-0.707107, 1.000000, 0.707106),
    glm::vec3(-0.831470, -1.000000, 0.555570),
    glm::vec3(-0.831470, 1.000000, 0.555570),
    glm::vec3(-0.923880, -1.000000, 0.382683),
    glm::vec3(-0.923880, 1.000000, 0.382683),
    glm::vec3(-0.980785, -1.000000, 0.195089),
    glm::vec3(-0.980785, 1.000000, 0.195089),
    glm::vec3(-1.000000, -1.000000, -0.000001),
    glm::vec3(-1.000000, 1.000000, -0.000001),
    glm::vec3(-0.980785, -1.000000, -0.195091),
    glm::vec3(-0.980785, 1.000000, -0.195091),
    glm::vec3(-0.923879, -1.000000, -0.382684),
    glm::vec3(-0.923879, 1.000000, -0.382684),
    glm::vec3(-0.831469, -1.000000, -0.555571),
    glm::vec3(-0.831469, 1.000000, -0.555571),
    glm::vec3(-0.707106, -1.000000, -0.707108),
    glm::vec3(-0.707106, 1.000000, -0.707108),
    glm::vec3(-0.555569, -1.000000, -0.831470),
    glm::vec3(-0.555569, 1.000000, -0.831470),
    glm::vec3(-0.382682, -1.000000, -0.923880),
    glm::vec3(-0.382682, 1.000000, -0.923880),
    glm::vec3(-0.195089, -1.000000, -0.980786),
    glm::vec3(-0.195089, 1.000000, -0.980786)
  };

  for (unsigned int i = 0; i < vertices_.size(); i++) {
    if (i < 2) {
      uvs_.push_back(glm::vec2(0.0, 0.0));
    } else {
      float u = (i-2)/(float)(vertices_.size()-3);
      float v = i % 2;
      uvs_.push_back(glm::vec2(u, v));
    }
  }

  for (unsigned int i = 0; i < vertices_.size(); i++) {
    if (i < 2) {
      normals_.push_back(glm::normalize(vertices_[i] - glm::vec3(0.0, 0.0, 0.0)));
    } else {
      normals_.push_back(glm::normalize(vertices_[i] - glm::vec3(0.0, vertices_[i].y, 0.0)));
    }
  }

  indices_ = {
    3, 1, 5,
    6, 2, 4,
    4, 3, 5,
    5, 1, 7,
    8, 2, 6,
    6, 5, 7,
    7, 1, 9,
    10, 2, 8,
    8, 7, 9,
    9, 1, 11,
    12, 2, 10,
    10, 9, 11,
    11, 1, 13,
    14, 2, 12,
    12, 11, 13,
    13, 1, 15,
    16, 2, 14,
    14, 13, 15,
    15, 1, 17,
    18, 2, 16,
    16, 15, 17,
    17, 1, 19,
    20, 2, 18,
    18, 17, 19,
    19, 1, 21,
    22, 2, 20,
    20, 19, 21,
    21, 1, 23,
    24, 2, 22,
    22, 21, 23,
    23, 1, 25,
    26, 2, 24,
    24, 23, 25,
    25, 1, 27,
    28, 2, 26,
    26, 25, 27,
    27, 1, 29,
    30, 2, 28,
    28, 27, 29,
    29, 1, 31,
    32, 2, 30,
    30, 29, 31,
    31, 1, 33,
    34, 2, 32,
    32, 31, 33,
    33, 1, 35,
    36, 2, 34,
    34, 33, 35,
    35, 1, 37,
    38, 2, 36,
    36, 35, 37,
    37, 1, 39,
    40, 2, 38,
    38, 37, 39,
    39, 1, 41,
    42, 2, 40,
    40, 39, 41,
    41, 1, 43,
    44, 2, 42,
    42, 41, 43,
    43, 1, 45,
    46, 2, 44,
    44, 43, 45,
    45, 1, 47,
    48, 2, 46,
    46, 45, 47,
    47, 1, 49,
    50, 2, 48,
    48, 47, 49,
    49, 1, 51,
    52, 2, 50,
    50, 49, 51,
    51, 1, 53,
    54, 2, 52,
    52, 51, 53,
    53, 1, 55,
    56, 2, 54,
    54, 53, 55,
    55, 1, 57,
    58, 2, 56,
    56, 55, 57,
    57, 1, 59,
    60, 2, 58,
    58, 57, 59,
    59, 1, 61,
    62, 2, 60,
    60, 59, 61,
    61, 1, 63,
    64, 2, 62,
    62, 61, 63,
    63, 1, 65,
    64, 63, 65,
    65, 1, 3,
    6, 4, 5,
    8, 6, 7,
    10, 8, 9,
    12, 10, 11,
    14, 12, 13,
    16, 14, 15,
    18, 16, 17,
    20, 18, 19,
    22, 20, 21,
    24, 22, 23,
    26, 24, 25,
    28, 26, 27,
    30, 28, 29,
    32, 30, 31,
    34, 32, 33,
    36, 34, 35,
    38, 36, 37,
    40, 38, 39,
    42, 40, 41,
    44, 42, 43,
    46, 44, 45,
    48, 46, 47,
    50, 48, 49,
    52, 50, 51,
    54, 52, 53,
    56, 54, 55,
    58, 56, 57,
    60, 58, 59,
    62, 60, 61,
    64, 62, 63,
    4, 2, 3,
    2, 65, 3,
    64, 65, 2
  };

  glGenVertexArrays(1, &VertexArrayID_);
  glBindVertexArray(VertexArrayID_);

  glGenBuffers(1, &vertexbuffer_);
  glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer_);
  glBufferData(GL_ARRAY_BUFFER, vertices_.size() * sizeof(glm::vec3),
               &vertices_[0], GL_STATIC_DRAW);
  glVertexAttribPointer(0,
                        3,
                        GL_FLOAT,
                        GL_FALSE,
                        0,
                        (void*)0);

  glGenBuffers(1, &normalbuffer_);
  glBindBuffer(GL_ARRAY_BUFFER, normalbuffer_);
  glBufferData(GL_ARRAY_BUFFER, normals_.size() * sizeof(glm::vec3),
               &normals_[0], GL_STATIC_DRAW);
  glVertexAttribPointer(1,
                        3,
                        GL_FLOAT,
                        GL_FALSE,
                        0,
                        (void*)0);

  glGenBuffers(1, &uvbuffer_);
  glBindBuffer(GL_ARRAY_BUFFER, uvbuffer_);
  glBufferData(GL_ARRAY_BUFFER, uvs_.size() * sizeof(glm::vec2),
               &uvs_[0], GL_STATIC_DRAW);
  glVertexAttribPointer(2,
                        2,
                        GL_FLOAT,
                        GL_FALSE,
                        0,
                        (void*)0);

  glGenBuffers(1, &elementbuffer_);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer_);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_.size() * sizeof(unsigned int),
               &indices_[0] , GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
  glEnableVertexAttribArray(2);

  glBindVertexArray(0);
}

Branch::~Branch() {
  glDeleteBuffers(1, &vertexbuffer_);
  glDeleteBuffers(1, &normalbuffer_);
  glDeleteBuffers(1, &uvbuffer_);
  glDeleteBuffers(1, &elementbuffer_);
  // glDeleteVertexArrays(1, &VertexArrayID_);
}

glm::mat4& Branch::getModelMatrix() {
  return model_;
}

void Branch::setModelMatrix(glm::mat4 matrix) {
  model_ = matrix;

}

void Branch::render() {
  glBindVertexArray(VertexArrayID_);
  glDrawElements(
      GL_TRIANGLES,
      indices_.size(),
      GL_UNSIGNED_INT,
      (void*)0
    );

  glBindVertexArray(0);
}