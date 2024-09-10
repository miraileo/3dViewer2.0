#ifndef BUTTONHANDLER_H
#define BUTTONHANDLER_H
#include <QColorDialog>
#include <QFile>
#include <QFileDialog>
#include <QLineEdit>
#include <QObject>
#include <QPushButton>

#include "../Model/OpenGL.h"
#include "../Model/affine_transformations.h"
#include "../View/ui_mainwindow.h"
class MainWindow;
namespace s21 {
class ButtonHandler : public QObject {
  Q_OBJECT
 public:
  ButtonHandler(MyOpenGLWidget* openGLWidget, MainWindow* mainwindow);
 public slots:
  void on_TransformEditX_editingFinished();
  void on_TransformEditY_editingFinished();
  void on_TransformEditZ_editingFinished();
  void on_RotateEditX_editingFinished();
  void on_RotateEditY_editingFinished();
  void on_RotateEditZ_editingFinished();
  void on_ScaleEdit_editingFinished();
  void on_IncreaseX_clicked();
  void on_IncreaseY_clicked();
  void on_IncreaseZ_clicked();
  void on_DeccreaseX_clicked();
  void on_DeccreaseY_clicked();
  void on_DeccreaseZ_clicked();
  void on_RotateIncreaseX_clicked();
  void on_RotateIncreaseY_clicked();
  void on_RotateIncreaseZ_clicked();
  void on_RotateDeccreaseX_clicked();
  void on_RotateDeccreaseY_clicked();
  void on_RotateDeccreaseZ_clicked();
  void on_ScaleIncrease_clicked();
  void on_ScaleDecrease_clicked();
  void on_BackGroundColor_clicked();
  void on_PointSize_editingFinished();
  void on_edgeColor_clicked();
  void on_pointColor_clicked();
  void on_DashedEdges_clicked();
  void on_OrthoProjection_clicked();
  void on_EdgeSize_editingFinished();
  void on_VertexTypeButton_clicked();
  void on_ScreenShot_clicked();
  void on_pushButton_clicked();

 private:
  MyOpenGLWidget* m_openGL;
  MainWindow* mainwindow;
  void ChangeValue(float newValue, float* currentvalue);
};
}  // namespace s21

#endif  // BUTTONHANDLER_H
