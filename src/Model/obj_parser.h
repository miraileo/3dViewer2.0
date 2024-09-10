#ifndef MODEL_H
#define MODEL_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
namespace s21 {
struct Vertex {
  float x, y, z;
};

struct Face {
  std::vector<int> vertex_indices;
};

class Model {
 public:
  std::vector<Vertex> vertices;
  std::vector<Face> faces;

  Model() = default;
  ~Model() = default;
};

Model* loadModel(const std::string& filename);
}  // namespace s21
#endif  // MODEL_H
