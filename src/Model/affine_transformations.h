#ifndef AFFINE_TRANSFORMATIONS_H
#define AFFINE_TRANSFORMATIONS_H
#include <cmath>
#include <vector>

#include "obj_parser.h"
namespace s21 {
float moveX(Model *model, float value, float translateX);
float moveY(Model *model, float value, float translateY);
float moveZ(Model *model, float value, float translateZ);
float rotateX(Model *model, float angle, float rotationX);
float rotateY(Model *model, float angle, float rotationY);
float rotateZ(Model *model, float angle, float rotationZ);
float scaleModel(Model *model, float increment, float currentScale);
}  // namespace s21
#endif  // AFFINE_TRANSFORMATIONS_H
