#include "affine_transformations.h"
namespace s21 {
float moveX(Model *model, float value, float translateX) {
  for (size_t i = 0; i < model->vertices.size(); i++) {
    model->vertices[i].x += value;
  }
  translateX += value;
  return translateX;
}

float moveY(Model *model, float value, float translateY) {
  for (size_t i = 0; i < model->vertices.size(); i++) {
    model->vertices[i].y += value;
  }
  translateY += value;
  return translateY;
}

float moveZ(Model *model, float value, float translateZ) {
  for (size_t i = 0; i < model->vertices.size(); i++) {
    model->vertices[i].z += value;
  }
  translateZ += value;
  return translateZ;
}

float rotateX(Model *model, float angle, float rotationX) {
  float radians = angle * (M_PI / 180.0f);
  for (size_t i = 0; i < model->vertices.size(); i++) {
    float y = model->vertices[i].y;
    float z = model->vertices[i].z;
    model->vertices[i].y = y * cos(-radians) - z * sin(-radians);
    model->vertices[i].z = y * sin(-radians) + z * cos(-radians);
  }
  rotationX += angle;
  return rotationX;
}

float rotateY(Model *model, float angle, float rotationY) {
  float radians = angle * (M_PI / 180.0f);
  for (size_t i = 0; i < model->vertices.size(); i++) {
    float x = model->vertices[i].x;
    float z = model->vertices[i].z;

    model->vertices[i].x = x * cos(-radians) - z * sin(-radians);
    model->vertices[i].z = x * sin(-radians) + z * cos(-radians);
  }
  rotationY += angle;
  return rotationY;
}

float rotateZ(Model *model, float angle, float rotationZ) {
  float radians = angle * (M_PI / 180.0f);
  for (size_t i = 0; i < model->vertices.size(); i++) {
    float x = model->vertices[i].x;
    float y = model->vertices[i].y;

    model->vertices[i].x = x * cos(-radians) - y * sin(-radians);
    model->vertices[i].y = x * sin(-radians) + y * cos(-radians);
  }
  rotationZ += angle;
  return rotationZ;
}

float scaleModel(Model *model, float increment, float currentScale) {
  if (currentScale + increment == 0) return currentScale;
  float newScale = currentScale + increment;
  float scaleFactor = newScale / currentScale;
  for (size_t i = 0; i < model->vertices.size(); i++) {
    model->vertices[i].x *= scaleFactor;
    model->vertices[i].y *= scaleFactor;
    model->vertices[i].z *= scaleFactor;
  }
  return newScale;
}
}  // namespace s21
