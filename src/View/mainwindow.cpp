#include "mainwindow.h"

#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  m_openGL = new s21::MyOpenGLWidget(nullptr);
  m_buttonHandler = new s21::ButtonHandler(m_openGL, this);
  ui->OpenGLWidget = m_openGL;
  ui->verticalLayout->addWidget(ui->OpenGLWidget);
  ui->OpenGLWidget->hide();
  ui->ScaleEdit->hide();
  ui->TransformEditX->hide();
  ui->TransformEditY->hide();
  ui->TransformEditZ->hide();
  ui->RotateEditX->hide();
  ui->RotateEditY->hide();
  ui->RotateEditZ->hide();
  setCentralWidget(ui->mainwidget);
  Connection();
}

MainWindow::~MainWindow() {
  m_openGL->SaveSettings();
  delete ui;
}
void MainWindow::Connection() {
  connect(ui->TransformEditX, &QLineEdit::editingFinished, m_buttonHandler,
          &s21::ButtonHandler::on_TransformEditX_editingFinished);
  connect(ui->TransformEditY, &QLineEdit::editingFinished, m_buttonHandler,
          &s21::ButtonHandler::on_TransformEditY_editingFinished);
  connect(ui->TransformEditZ, &QLineEdit::editingFinished, m_buttonHandler,
          &s21::ButtonHandler::on_TransformEditZ_editingFinished);
  connect(ui->RotateEditX, &QLineEdit::editingFinished, m_buttonHandler,
          &s21::ButtonHandler::on_RotateEditX_editingFinished);
  connect(ui->RotateEditY, &QLineEdit::editingFinished, m_buttonHandler,
          &s21::ButtonHandler::on_RotateEditY_editingFinished);
  connect(ui->RotateEditZ, &QLineEdit::editingFinished, m_buttonHandler,
          &s21::ButtonHandler::on_RotateEditZ_editingFinished);
  connect(ui->ScaleEdit, &QLineEdit::editingFinished, m_buttonHandler,
          &s21::ButtonHandler::on_ScaleEdit_editingFinished);
  connect(ui->PointSize, &QLineEdit::editingFinished, m_buttonHandler,
          &s21::ButtonHandler::on_PointSize_editingFinished);
  connect(ui->EdgeSize, &QLineEdit::editingFinished, m_buttonHandler,
          &s21::ButtonHandler::on_EdgeSize_editingFinished);
  connect(ui->IncreaseX, &QPushButton::clicked, m_buttonHandler,
          &s21::ButtonHandler::on_IncreaseX_clicked);
  connect(ui->DeccreaseX, &QPushButton::clicked, m_buttonHandler,
          &s21::ButtonHandler::on_DeccreaseX_clicked);
  connect(ui->IncreaseY, &QPushButton::clicked, m_buttonHandler,
          &s21::ButtonHandler::on_IncreaseY_clicked);
  connect(ui->DeccreaseY, &QPushButton::clicked, m_buttonHandler,
          &s21::ButtonHandler::on_DeccreaseY_clicked);
  connect(ui->IncreaseZ, &QPushButton::clicked, m_buttonHandler,
          &s21::ButtonHandler::on_IncreaseZ_clicked);
  connect(ui->DeccreaseZ, &QPushButton::clicked, m_buttonHandler,
          &s21::ButtonHandler::on_DeccreaseZ_clicked);
  connect(ui->RotateIncreaseX, &QPushButton::clicked, m_buttonHandler,
          &s21::ButtonHandler::on_RotateIncreaseX_clicked);
  connect(ui->RotateDeccreaseX, &QPushButton::clicked, m_buttonHandler,
          &s21::ButtonHandler::on_RotateDeccreaseX_clicked);
  connect(ui->RotateIncreaseY, &QPushButton::clicked, m_buttonHandler,
          &s21::ButtonHandler::on_RotateIncreaseY_clicked);
  connect(ui->RotateDeccreaseY, &QPushButton::clicked, m_buttonHandler,
          &s21::ButtonHandler::on_RotateDeccreaseY_clicked);
  connect(ui->RotateIncreaseZ, &QPushButton::clicked, m_buttonHandler,
          &s21::ButtonHandler::on_RotateIncreaseZ_clicked);
  connect(ui->RotateDeccreaseZ, &QPushButton::clicked, m_buttonHandler,
          &s21::ButtonHandler::on_RotateDeccreaseZ_clicked);
  connect(ui->ScaleIncrease, &QPushButton::clicked, m_buttonHandler,
          &s21::ButtonHandler::on_ScaleIncrease_clicked);
  connect(ui->ScaleDecrease, &QPushButton::clicked, m_buttonHandler,
          &s21::ButtonHandler::on_ScaleDecrease_clicked);
  connect(ui->BackGroundColor, &QPushButton::clicked, m_buttonHandler,
          &s21::ButtonHandler::on_BackGroundColor_clicked);
  connect(ui->pointColor, &QPushButton::clicked, m_buttonHandler,
          &s21::ButtonHandler::on_pointColor_clicked);
  connect(ui->edgeColor, &QPushButton::clicked, m_buttonHandler,
          &s21::ButtonHandler::on_edgeColor_clicked);
  connect(ui->DashedEdges, &QPushButton::clicked, m_buttonHandler,
          &s21::ButtonHandler::on_DashedEdges_clicked);
  connect(ui->OrthoProjection, &QPushButton::clicked, m_buttonHandler,
          &s21::ButtonHandler::on_OrthoProjection_clicked);
  connect(ui->VertexTypeButton, &QPushButton::clicked, m_buttonHandler,
          &s21::ButtonHandler::on_VertexTypeButton_clicked);
  connect(ui->ScreenShot, &QPushButton::clicked, m_buttonHandler,
          &s21::ButtonHandler::on_ScreenShot_clicked);
  connect(ui->pushButton, &QPushButton::clicked, m_buttonHandler,
          &s21::ButtonHandler::on_pushButton_clicked);
}

void MainWindow::showModelInfo() {
  int numOfEdges = 0;
  int lastSlash = fileName.lastIndexOf('/');
  QString _fileName = fileName.mid(lastSlash + 1);
  int lastDot = _fileName.lastIndexOf('.');
  if (lastDot != -1) {
    _fileName = _fileName.left(lastDot);
  }
  for (size_t i = 0; i < m_openGL->m_model->faces.size(); i++)
    numOfEdges += m_openGL->m_model->faces[i].vertex_indices.size();
  ui->ModelInfo->setText("Model: " + _fileName + "<br>" + " V: " +
                         QString::number(m_openGL->m_model->vertices.size()) +
                         ", " + " E: " + QString::number(numOfEdges / 2));
}

void MainWindow::updateUIFromModel() {
  ui->TransformEditX->setText(QString::number(m_openGL->m_translateX));
  ui->TransformEditY->setText(QString::number(m_openGL->m_translateY));
  ui->TransformEditZ->setText(QString::number(m_openGL->m_translateZ));
  ui->RotateEditX->setText(QString::number(m_openGL->m_rotationX));
  ui->RotateEditY->setText(QString::number(m_openGL->m_rotationY));
  ui->RotateEditZ->setText(QString::number(m_openGL->m_rotationZ));
  ui->ScaleEdit->setText(QString::number(m_openGL->m_scale));
  ui->PointSize->setText(QString::number(m_openGL->m_pointSize));
  ui->EdgeSize->setText(QString::number(m_openGL->m_lineSize));
}
