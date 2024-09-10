#include "OpenGL.h"
namespace s21 {
MyOpenGLWidget::MyOpenGLWidget(QWidget *parent, Model *model)
    : QOpenGLWidget(parent),
      m_model(model),
      m_backgroundColor(1),
      m_pointColor(1),
      m_edgeColor(1),
      m_zoom(1.0f),
      m_rotationX(0.0f),
      m_rotationY(0.0f),
      m_rotationZ(0.0f),
      m_scale(1.0f),
      m_translateX(0.0f),
      m_translateY(0.0f),
      m_translateZ(0.0f),
      m_pointSize(2),
      m_lineSize(2),
      stripLine(false),
      orthoProjection(false),
      circleVertex(false),
      squareVertex(false) {}

MyOpenGLWidget::~MyOpenGLWidget() {}

void MyOpenGLWidget::setModel(Model *model) {
  m_model = model;
  update();
}

void MyOpenGLWidget::initializeGL() {
  initializeOpenGLFunctions();
  glEnable(GL_DEPTH_TEST);
}

void MyOpenGLWidget::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0, w / (float)h, 0.1, 1000.0);
  glMatrixMode(GL_MODELVIEW);
}

void MyOpenGLWidget::paintGL() {
  UpdateProjection();
  glClearColor(m_backgroundColor.redF(), m_backgroundColor.greenF(),
               m_backgroundColor.blueF(), 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  gluLookAt(0, 0, 0 + (5.0f * m_zoom), 0, 0, 0, 0.0, 1.0, 0.0);
  DrawVertexes();
  DrawEdges();
  glFlush();
}

void MyOpenGLWidget::UpdateProjection() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  float aspect = static_cast<float>(width()) / static_cast<float>(height());
  if (orthoProjection)
    glOrtho(-aspect, aspect, -1.0, 1.0, 0.1, 1000.0);
  else
    gluPerspective(45.0, aspect, 0.1, 1000.0);
  glMatrixMode(GL_MODELVIEW);
}

void MyOpenGLWidget::DrawEdges() {
  glColor3f(m_edgeColor.redF(), m_edgeColor.greenF(), m_edgeColor.blueF());
  glLineWidth(m_lineSize);
  if (stripLine) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(7, 7);
  } else
    glDisable(GL_LINE_STIPPLE);
  glBegin(GL_LINES);
  for (const auto &face : m_model->faces) {
    for (size_t j = 0; j < face.vertex_indices.size(); ++j) {
      int current_index = face.vertex_indices[j] - 1;
      int next_index =
          face.vertex_indices[(j + 1) % face.vertex_indices.size()] - 1;
      glVertex3f(m_model->vertices[current_index].x,
                 m_model->vertices[current_index].y,
                 m_model->vertices[current_index].z);
      glVertex3f(m_model->vertices[next_index].x,
                 m_model->vertices[next_index].y,
                 m_model->vertices[next_index].z);
    }
  }
  glEnd();
}

void MyOpenGLWidget::DrawVertexes() {
  glColor3f(m_pointColor.redF(), m_pointColor.greenF(), m_pointColor.blueF());
  if (squareVertex || circleVertex) {
    glPointSize(m_pointSize);
    if (circleVertex)
      glEnable(GL_POINT_SMOOTH);
    else if (squareVertex)
      glDisable(GL_POINT_SMOOTH);
    glBegin(GL_POINTS);
    for (size_t i = 0; i < m_model->vertices.size(); i++) {
      glVertex3f(m_model->vertices[i].x, m_model->vertices[i].y,
                 m_model->vertices[i].z);
    }
    glEnd();
  }
}

void MyOpenGLWidget::SaveSettings() {
  QFile file("Settings.txt");
  if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    QTextStream out(&file);
    out << "BackgroundColor: " << m_backgroundColor.name() << "\n";
    out << "PointColor: " << m_pointColor.name() << "\n";
    out << "EdgeColor: " << m_edgeColor.name() << "\n";
    out << "Zoom: " << m_zoom << "\n";
    out << "RotationX: " << m_rotationX << "\n";
    out << "RotationY: " << m_rotationY << "\n";
    out << "RotationZ: " << m_rotationZ << "\n";
    out << "Scale: " << m_scale << "\n";
    out << "TranslateX: " << m_translateX << "\n";
    out << "TranslateY: " << m_translateY << "\n";
    out << "TranslateZ: " << m_translateZ << "\n";
    out << "PointSize: " << m_pointSize << "\n";
    out << "LineSize: " << m_lineSize << "\n";
    out << "StripLine: " << (stripLine ? "True" : "False") << "\n";
    out << "OrthoProjection: " << (orthoProjection ? "True" : "False") << "\n";
    out << "CircleVertex: " << (circleVertex ? "True" : "False") << "\n";
    out << "SquareVertex: " << (squareVertex ? "True" : "False") << "\n";
    file.close();
  }
}

void MyOpenGLWidget::LoadSettings() {
  QFile file("Settings.txt");
  if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    QTextStream in(&file);

    while (!in.atEnd()) {
      QString line = in.readLine();
      QStringList parts = line.split(": ");
      if (parts.size() == 2) {
        QString key = parts[0];
        QString value = parts[1];
        if (key == "BackgroundColor")
          m_backgroundColor = QColor(value);
        else if (key == "PointColor")
          m_pointColor = QColor(value);
        else if (key == "EdgeColor")
          m_edgeColor = QColor(value);
        else if (key == "Zoom")
          m_zoom = value.toFloat();
        else if (key == "RotationX") {
          m_rotationX = value.toFloat();
          rotateX(m_model, m_rotationX, m_rotationX);
        } else if (key == "RotationY") {
          m_rotationY = value.toFloat();
          rotateY(m_model, m_rotationY, m_rotationY);
        } else if (key == "RotationZ") {
          m_rotationZ = value.toFloat();
          rotateZ(m_model, m_rotationZ, m_rotationZ);
        } else if (key == "Scale") {
          m_scale = value.toFloat();
          scaleModel(m_model, 0, m_scale);
        } else if (key == "TranslateX") {
          m_translateX = value.toFloat();
          moveX(m_model, m_translateX, m_translateX);
        } else if (key == "TranslateY") {
          m_translateY = value.toFloat();
          moveY(m_model, m_translateY, m_translateY);
        } else if (key == "TranslateZ") {
          m_translateZ = value.toFloat();
          moveZ(m_model, m_translateZ, m_translateZ);
        } else if (key == "PointSize")
          m_pointSize = value.toFloat();
        else if (key == "LineSize")
          m_lineSize = value.toFloat();
        else if (key == "StripLine")
          stripLine = (value == "True");
        else if (key == "OrthoProjection")
          orthoProjection = (value == "True");
        else if (key == "CircleVertex")
          circleVertex = (value == "True");
        else if (key == "SquareVertex")
          squareVertex = (value == "True");
      }
    }
    file.close();
  }
}

void MyOpenGLWidget::wheelEvent(QWheelEvent *event) {
  if (event->angleDelta().y() > 0) {
    m_zoom *= 0.9f;
  } else {
    m_zoom *= 1.1f;
  }
  update();
}
}  // namespace s21
