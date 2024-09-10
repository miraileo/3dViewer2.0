#include <gtest/gtest.h>

#include "Model/affine_transformations.cpp"
#include "Model/obj_parser.cpp"
using namespace s21;

// Мок-класс для модели, чтобы избежать зависимости от реального файла
class MockModel : public Model {
 public:
  MockModel() {
    vertices = {
        {1.0f, 2.0f, 3.0f},
        {4.0f, 5.0f, 6.0f},
        {7.0f, 8.0f, 9.0f},
    };
  }
};

// Тест для функции moveX
TEST(AffineTransformationsTest, MoveXTest) {
  MockModel model;
  float translateX = 0.0f;
  translateX = moveX(&model, 1.0f, translateX);

  EXPECT_FLOAT_EQ(model.vertices[0].x, 2.0f);
  EXPECT_FLOAT_EQ(model.vertices[1].x, 5.0f);
  EXPECT_FLOAT_EQ(model.vertices[2].x, 8.0f);
  EXPECT_FLOAT_EQ(translateX, 1.0f);
}

// Тест для функции moveY
TEST(AffineTransformationsTest, MoveYTest) {
  MockModel model;
  float translateY = 0.0f;
  translateY = moveY(&model, 1.0f, translateY);

  EXPECT_FLOAT_EQ(model.vertices[0].y, 3.0f);
  EXPECT_FLOAT_EQ(model.vertices[1].y, 6.0f);
  EXPECT_FLOAT_EQ(model.vertices[2].y, 9.0f);
  EXPECT_FLOAT_EQ(translateY, 1.0f);
}

// Тест для функции moveZ
TEST(AffineTransformationsTest, MoveZTest) {
  MockModel model;
  float translateZ = 0.0f;
  translateZ = moveZ(&model, 1.0f, translateZ);

  EXPECT_FLOAT_EQ(model.vertices[0].z, 4.0f);
  EXPECT_FLOAT_EQ(model.vertices[1].z, 7.0f);
  EXPECT_FLOAT_EQ(model.vertices[2].z, 10.0f);
  EXPECT_FLOAT_EQ(translateZ, 1.0f);
}

// Тест для функции rotateX
TEST(AffineTransformationsTest, RotateXTest) {
  MockModel model;
  float rotationX = 0.0f;
  rotationX = rotateX(&model, 90.0f, rotationX);

  EXPECT_NEAR(model.vertices[0].y, 3.0f, 1e-6);
  EXPECT_NEAR(model.vertices[0].z, -2.0f, 1e-6);
  EXPECT_NEAR(model.vertices[1].y, 6.0f, 1e-6);
  EXPECT_NEAR(model.vertices[1].z, -5.0f, 1e-6);
  EXPECT_NEAR(rotationX, 90.0f, 1e-6);
}

// Тест для функции rotateY
TEST(AffineTransformationsTest, RotateYTest) {
  MockModel model;
  float rotationY = 0.0f;
  rotationY = rotateY(&model, 90.0f, rotationY);

  EXPECT_NEAR(model.vertices[0].x, 3.0f, 1e-6);
  EXPECT_NEAR(model.vertices[0].z, -1.0f, 1e-6);
  EXPECT_NEAR(model.vertices[1].x, 6.0f, 1e-6);
  EXPECT_NEAR(model.vertices[1].z, -4.0f, 1e-6);
  EXPECT_NEAR(rotationY, 90.0f, 1e-6);
}

// Тест для функции rotateZ
TEST(AffineTransformationsTest, RotateZTest) {
  MockModel model;
  float rotationZ = 0.0f;
  rotationZ = rotateZ(&model, 90.0f, rotationZ);

  EXPECT_NEAR(model.vertices[0].x, 2.0f, 1e-6);
  EXPECT_NEAR(model.vertices[0].y, -1.0f, 1e-6);
  EXPECT_NEAR(model.vertices[1].x, 5.0f, 1e-6);
  EXPECT_NEAR(model.vertices[1].y, -4.0f, 1e-6);
  EXPECT_NEAR(rotationZ, 90.0f, 1e-6);
}

// Тест для функции scaleModel
TEST(AffineTransformationsTest, ScaleModelTest) {
  MockModel model;
  float scale = 1.0f;
  scale = scaleModel(&model, 1.0f, scale);

  EXPECT_FLOAT_EQ(model.vertices[0].x, 2.0f);
  EXPECT_FLOAT_EQ(model.vertices[0].y, 4.0f);
  EXPECT_FLOAT_EQ(model.vertices[0].z, 6.0f);
  EXPECT_FLOAT_EQ(scale, 2.0f);
}

TEST(Obj_ParserTest, VertexEdgeTest) {
  Model *model = loadModel("models/cube2.obj");
  for (int i = 0; i < 8; i++) {
    if (i < 4)
      EXPECT_FLOAT_EQ(model->vertices[i].x, 1);
    else
      EXPECT_FLOAT_EQ(model->vertices[i].x, -1);
  }
  float val = 1;
  for (int i = 0; i < 8; i++) {
    EXPECT_FLOAT_EQ(model->vertices[i].y, val);
    val *= -1;
  }
  for (int i = 0; i < 8; i++) {
    if (i % 2 == 0) val *= -1;
    EXPECT_FLOAT_EQ(model->vertices[i].z, val);
  }
  EXPECT_FLOAT_EQ(model->faces[0].vertex_indices[0], 1);
  EXPECT_FLOAT_EQ(model->faces[0].vertex_indices[1], 5);
  EXPECT_FLOAT_EQ(model->faces[0].vertex_indices[2], 7);
  EXPECT_FLOAT_EQ(model->faces[0].vertex_indices[3], 3);
  EXPECT_FLOAT_EQ(model->faces[1].vertex_indices[0], 4);
  EXPECT_FLOAT_EQ(model->faces[1].vertex_indices[1], 3);
  EXPECT_FLOAT_EQ(model->faces[1].vertex_indices[2], 7);
  EXPECT_FLOAT_EQ(model->faces[1].vertex_indices[3], 8);
  EXPECT_FLOAT_EQ(model->faces[2].vertex_indices[0], 8);
  EXPECT_FLOAT_EQ(model->faces[2].vertex_indices[1], 7);
  EXPECT_FLOAT_EQ(model->faces[2].vertex_indices[2], 5);
  EXPECT_FLOAT_EQ(model->faces[2].vertex_indices[3], 6);
  EXPECT_FLOAT_EQ(model->faces[3].vertex_indices[0], 6);
  EXPECT_FLOAT_EQ(model->faces[3].vertex_indices[1], 2);
  EXPECT_FLOAT_EQ(model->faces[3].vertex_indices[2], 4);
  EXPECT_FLOAT_EQ(model->faces[3].vertex_indices[3], 8);
  EXPECT_FLOAT_EQ(model->faces[4].vertex_indices[0], 2);
  EXPECT_FLOAT_EQ(model->faces[4].vertex_indices[1], 1);
  EXPECT_FLOAT_EQ(model->faces[4].vertex_indices[2], 3);
  EXPECT_FLOAT_EQ(model->faces[4].vertex_indices[3], 4);
  EXPECT_FLOAT_EQ(model->faces[5].vertex_indices[0], 6);
  EXPECT_FLOAT_EQ(model->faces[5].vertex_indices[1], 5);
  EXPECT_FLOAT_EQ(model->faces[5].vertex_indices[2], 1);
  EXPECT_FLOAT_EQ(model->faces[5].vertex_indices[3], 2);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
