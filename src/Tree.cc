#include "Tree.h"

Tree::Tree(std::mt19937 &rng) : rng_(rng) {
}

Tree::~Tree() {
  glDeleteTextures(1, &textureID_);
}

void Tree::generateTree(Terrain &terrain) {
  string_ = "X";

  texture_ = Helper::loadDDS("resources/bark.dds");

  for (unsigned int i = 0; i < 4; i++) {
    for (unsigned int j = 0; j < string_.size(); j++) {
      if (string_.at(j) == 'X') {
        string_.replace(j, 1, "B[RX]B[RX]RX");
        j += 11;
      } else if (string_.at(j) == 'B') {
        string_.replace(j, 1, "BB");
        j += 1;
      }
    }
  }

  branches_.clear();

  std::uniform_int_distribution<uint32_t> uint_dist(1, 98);
  int x = uint_dist(rng_);
  int z = uint_dist(rng_);

  position_ = glm::vec3(x, terrain.getHeight(glm::vec3(x, 0, z)), z);
  model_ = glm::mat4(1.0f);
  model_ = glm::translate(model_,
                          glm::vec3(position_.x, position_.y-1, position_.z));
  model_ = glm::scale(model_, glm::vec3(0.5, 0.5, 0.5));

  std::vector<glm::mat4> workingMatrix;

  workingMatrix.push_back(model_);
  for (unsigned int i = 0; i < string_.size(); i++){
    if (string_.at(i) == '[') {
      workingMatrix.push_back(workingMatrix.back());
    } else if (string_.at(i) == ']') {
      workingMatrix.pop_back();
    } else if (string_.at(i) == 'B') {
      workingMatrix.back() = glm::translate(workingMatrix.back(),
                                            glm::vec3(0, 2, 0));
      branches_.push_back(branch);
      branches_.back().setModelMatrix(workingMatrix.back());
    } else if (string_.at(i) == 'T') {
      workingMatrix.back() = glm::translate(workingMatrix.back(),
                                            glm::vec3(0, 1, 0));
    } else if (string_.at(i) == 'R') {
      std::uniform_int_distribution<uint32_t> uint_dist(0, 360);
      workingMatrix.back() = glm::rotate(workingMatrix.back(),
                                    (float)uint_dist(rng_), glm::vec3(0, 1, 0));
      workingMatrix.back() = glm::rotate(workingMatrix.back(),
                                  -45.0f, glm::vec3(1, 0, 0));
      workingMatrix.back() = glm::scale(workingMatrix.back(),
                                        glm::vec3(0.8, 0.8, 0.8));
    } else if (string_.at(i) == 'S') {
      workingMatrix.back() = glm::scale(workingMatrix.back(),
                                        glm::vec3(1, 1.5, 1));
    }
  }
}

void Tree::setPosition(glm::vec3 position) {
  position_ = position;
}

void Tree::render(GLuint programID, glm::mat4 &projection, glm::mat4 &view) {
  glUseProgram(programID);

  matrixID_ = glGetUniformLocation(programID, "MVP");
  mID_ = glGetUniformLocation(programID, "M");
  vID_ = glGetUniformLocation(programID, "V");

  textureID_ = glGetUniformLocation(programID, "textureSampler");

  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, texture_);
  glUniform1i(textureID_, 0);

  for (auto& branch : branches_) {
    MVP_ = projection * view * branch.getModelMatrix();

    glUniformMatrix4fv(matrixID_, 1, GL_FALSE, &MVP_[0][0]);
    glUniformMatrix4fv(mID_, 1, GL_FALSE, &view[0][0]);
    glUniformMatrix4fv(vID_, 1, GL_FALSE, &branch.getModelMatrix()[0][0]);

    branch.render();
  }
}