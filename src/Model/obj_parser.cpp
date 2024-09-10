#include "obj_parser.h"
namespace s21 {
Model* loadModel(const std::string& filename) {
  std::ifstream infile(filename);
  if (!infile.is_open()) {
    std::cerr << "Error opening file" << std::endl;
    return nullptr;
  }
  Model* model = new Model();
  std::string line;
  std::string number;
  while (std::getline(infile, line)) {
    if (line.substr(0, 2) == "v ") {
      std::istringstream iss(line.substr(2));
      Vertex vertex;
      iss >> vertex.x >> vertex.y >> vertex.z;
      model->vertices.push_back(vertex);
    } else if (line.substr(0, 2) == "f ") {
      std::istringstream iss(line.substr(2));
      Face face;
      std::string vertex_data;
      while (iss >> vertex_data) {
        std::istringstream vertex_iss(vertex_data);
        int vertex_index;
        if (vertex_iss >> vertex_index) {
          face.vertex_indices.push_back(vertex_index);
        }
      }
      model->faces.push_back(face);
    }
  }
  return model;
}
}  // namespace s21
