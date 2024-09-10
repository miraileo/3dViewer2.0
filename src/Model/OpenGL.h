#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include <GL/glu.h>
#include <math.h>

#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QTextStream>
#include <QWheelEvent>

#include "affine_transformations.h"
#include "obj_parser.h"

class ButtonHandler;
class MainWindow;
namespace s21 {
class MyOpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT
  friend class ButtonHandler;
  friend class ::MainWindow;

 public:
  MyOpenGLWidget(QWidget *parent = nullptr, Model *model = nullptr);
  ~MyOpenGLWidget();

  void setModel(Model *model);

 protected:
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;
  void wheelEvent(QWheelEvent *event) override;

 private:
  Model *m_model;
  QColor m_backgroundColor;
  QColor m_pointColor;
  QColor m_edgeColor;
  float m_zoom;
  float m_rotationX;
  float m_rotationY;
  float m_rotationZ;
  float m_scale;
  float m_translateX;
  float m_translateY;
  float m_translateZ;
  float m_pointSize;
  float m_lineSize;
  bool stripLine;
  bool orthoProjection;
  bool circleVertex;
  bool squareVertex;
  void UpdateProjection();
  void DrawEdges();
  void DrawVertexes();
  void SaveSettings();
  void LoadSettings();
};
}  // namespace s21
#endif  // MYOPENGLWIDGET_H
