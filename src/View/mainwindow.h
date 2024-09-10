#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QColorDialog>
#include <QFile>
#include <QFileDialog>
#include <QLineEdit>
#include <QMainWindow>
#include <QTextStream>

#include "../Controller/buttonhandler.h"
#include "../Model/OpenGL.h"
#include "../Model/affine_transformations.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT
  friend class s21::ButtonHandler;

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  s21::MyOpenGLWidget *m_openGL;
  QString fileName;
  s21::ButtonHandler *m_buttonHandler;
  void Connection();
  void updateUIFromModel();
  void showModelInfo();
};
#endif  // MAINWINDOW_H
