#include "buttonhandler.h"

#include "../View/mainwindow.h"
namespace s21 {
ButtonHandler::ButtonHandler(MyOpenGLWidget *openGLWidget,
                             MainWindow *mainwindow)
    : m_openGL(openGLWidget), mainwindow(mainwindow) {}

void ButtonHandler::on_TransformEditX_editingFinished() {
  ChangeValue(moveX(m_openGL->m_model,
                    mainwindow->ui->TransformEditX->text().toFloat() -
                        m_openGL->m_translateX,
                    m_openGL->m_translateX),
              &m_openGL->m_translateX);
}
void ButtonHandler::on_TransformEditY_editingFinished() {
  ChangeValue(moveY(m_openGL->m_model,
                    mainwindow->ui->TransformEditY->text().toFloat() -
                        m_openGL->m_translateY,
                    m_openGL->m_translateY),
              &m_openGL->m_translateY);
}
void ButtonHandler::on_TransformEditZ_editingFinished() {
  ChangeValue(moveZ(m_openGL->m_model,
                    mainwindow->ui->TransformEditZ->text().toFloat() -
                        m_openGL->m_translateZ,
                    m_openGL->m_translateZ),
              &m_openGL->m_translateZ);
}
void ButtonHandler::on_RotateEditX_editingFinished() {
  ChangeValue(rotateX(m_openGL->m_model,
                      mainwindow->ui->RotateEditX->text().toFloat() -
                          m_openGL->m_rotationX,
                      m_openGL->m_rotationX),
              &m_openGL->m_rotationX);
}
void ButtonHandler::on_RotateEditY_editingFinished() {
  ChangeValue(rotateY(m_openGL->m_model,
                      mainwindow->ui->RotateEditY->text().toFloat() -
                          m_openGL->m_rotationY,
                      m_openGL->m_rotationY),
              &m_openGL->m_rotationY);
}
void ButtonHandler::on_RotateEditZ_editingFinished() {
  ChangeValue(rotateZ(m_openGL->m_model,
                      mainwindow->ui->RotateEditZ->text().toFloat() -
                          m_openGL->m_rotationZ,
                      m_openGL->m_rotationZ),
              &m_openGL->m_rotationZ);
}
void ButtonHandler::on_ScaleEdit_editingFinished() {
  ChangeValue(scaleModel(m_openGL->m_model,
                         mainwindow->ui->ScaleEdit->text().toFloat() -
                             m_openGL->m_scale,
                         m_openGL->m_scale),
              &m_openGL->m_scale);
}
void ButtonHandler::on_IncreaseX_clicked() {
  ChangeValue(moveX(m_openGL->m_model, 0.5f, m_openGL->m_translateX),
              &m_openGL->m_translateX);
}
void ButtonHandler::on_DeccreaseX_clicked() {
  ChangeValue(moveX(m_openGL->m_model, -0.5f, m_openGL->m_translateX),
              &m_openGL->m_translateX);
}
void ButtonHandler::on_DeccreaseY_clicked() {
  ChangeValue(moveY(m_openGL->m_model, -0.5f, m_openGL->m_translateY),
              &m_openGL->m_translateY);
}
void ButtonHandler::on_IncreaseY_clicked() {
  ChangeValue(moveY(m_openGL->m_model, 0.5f, m_openGL->m_translateY),
              &m_openGL->m_translateY);
}
void ButtonHandler::on_DeccreaseZ_clicked() {
  ChangeValue(moveZ(m_openGL->m_model, -0.5f, m_openGL->m_translateZ),
              &m_openGL->m_translateZ);
}
void ButtonHandler::on_IncreaseZ_clicked() {
  ChangeValue(moveZ(m_openGL->m_model, 0.5f, m_openGL->m_translateZ),
              &m_openGL->m_translateZ);
}
void ButtonHandler::on_RotateIncreaseX_clicked() {
  ChangeValue(rotateX(m_openGL->m_model, 0.5f, m_openGL->m_rotationX),
              &m_openGL->m_rotationX);
}
void ButtonHandler::on_RotateDeccreaseX_clicked() {
  ChangeValue(rotateX(m_openGL->m_model, -0.5f, m_openGL->m_rotationX),
              &m_openGL->m_rotationX);
}
void ButtonHandler::on_RotateIncreaseY_clicked() {
  ChangeValue(rotateY(m_openGL->m_model, 0.5f, m_openGL->m_rotationY),
              &m_openGL->m_rotationY);
}
void ButtonHandler::on_RotateDeccreaseY_clicked() {
  ChangeValue(rotateY(m_openGL->m_model, -0.5f, m_openGL->m_rotationY),
              &m_openGL->m_rotationY);
}
void ButtonHandler::on_RotateIncreaseZ_clicked() {
  ChangeValue(rotateZ(m_openGL->m_model, 0.5f, m_openGL->m_rotationZ),
              &m_openGL->m_rotationZ);
}
void ButtonHandler::on_RotateDeccreaseZ_clicked() {
  ChangeValue(rotateZ(m_openGL->m_model, -0.5f, m_openGL->m_rotationZ),
              &m_openGL->m_rotationZ);
}
void ButtonHandler::on_ScaleIncrease_clicked() {
  ChangeValue(scaleModel(m_openGL->m_model, 0.5f, m_openGL->m_scale),
              &m_openGL->m_scale);
}
void ButtonHandler::on_ScaleDecrease_clicked() {
  ChangeValue(scaleModel(m_openGL->m_model, -0.5f, m_openGL->m_scale),
              &m_openGL->m_scale);
}
void ButtonHandler::on_BackGroundColor_clicked() {
  QColor color =
      QColorDialog::getColor(Qt::white, nullptr, "Choose Background Color");
  m_openGL->m_backgroundColor = color;
  m_openGL->update();
}
void ButtonHandler::on_edgeColor_clicked() {
  QColor color =
      QColorDialog::getColor(Qt::white, nullptr, "Choose Edge Color");
  m_openGL->m_edgeColor = color;
  m_openGL->update();
}
void ButtonHandler::on_pointColor_clicked() {
  QColor color =
      QColorDialog::getColor(Qt::white, nullptr, "Choose Point Color");
  m_openGL->m_pointColor = color;
  m_openGL->update();
}
void ButtonHandler::on_DashedEdges_clicked() {
  if (!m_openGL->stripLine)
    m_openGL->stripLine = true;
  else
    m_openGL->stripLine = false;
  m_openGL->update();
}
void ButtonHandler::on_OrthoProjection_clicked() {
  if (!m_openGL->orthoProjection)
    m_openGL->orthoProjection = true;
  else
    m_openGL->orthoProjection = false;
  m_openGL->update();
}
void ButtonHandler::on_VertexTypeButton_clicked() {
  if (!m_openGL->circleVertex && !m_openGL->squareVertex) {
    mainwindow->ui->VertexTypeButton->setText("Square");
    m_openGL->squareVertex = true;
    m_openGL->circleVertex = false;
  } else if (m_openGL->squareVertex && !m_openGL->circleVertex) {
    mainwindow->ui->VertexTypeButton->setText("Circle");
    m_openGL->squareVertex = false;
    m_openGL->circleVertex = true;
  } else if (!m_openGL->squareVertex && m_openGL->circleVertex) {
    mainwindow->ui->VertexTypeButton->setText("None");
    m_openGL->squareVertex = false;
    m_openGL->circleVertex = false;
  }
  m_openGL->update();
}
void ButtonHandler::on_EdgeSize_editingFinished() {
  m_openGL->m_lineSize = mainwindow->ui->EdgeSize->text().toFloat();
  mainwindow->ui->EdgeSize->setText(QString::number(m_openGL->m_lineSize));
  m_openGL->update();
}
void ButtonHandler::on_PointSize_editingFinished() {
  m_openGL->m_pointSize = mainwindow->ui->PointSize->text().toFloat();
  m_openGL->update();
}
void ButtonHandler::on_ScreenShot_clicked() {
  QImage screenshot = m_openGL->grabFramebuffer();
  QFileDialog dialog(nullptr, "Сохранить изображение", "",
                     "BMP Files (*.bmp);;JPEG Files (*.jpg *.jpeg)");
  dialog.setAcceptMode(QFileDialog::AcceptSave);

  if (dialog.exec() == QDialog::Accepted) {
    QString fileName = dialog.selectedFiles().first();
    QString selectedFilter = dialog.selectedNameFilter();
    if (selectedFilter.contains("BMP")) {
      if (!fileName.endsWith(".bmp", Qt::CaseInsensitive)) {
        fileName += ".bmp";
      }
    } else if (selectedFilter.contains("JPEG") ||
               selectedFilter.contains("JPG")) {
      if (!fileName.endsWith(".jpg", Qt::CaseInsensitive) &&
          !fileName.endsWith(".jpeg", Qt::CaseInsensitive)) {
        fileName += ".jpg";
      }
    }
    screenshot.save(fileName);
  }
}
void ButtonHandler::ChangeValue(float newValue, float *currentvalue) {
  *currentvalue = newValue;
  mainwindow->updateUIFromModel();
  m_openGL->update();
}
void ButtonHandler::on_pushButton_clicked() {
  mainwindow->fileName = QFileDialog::getOpenFileName(
      nullptr, "Open model", "../models/", "model (*.obj)");
  if (!mainwindow->fileName.isEmpty()) {
    Model *model = loadModel(mainwindow->fileName.toStdString().c_str());
    if (model) {
      m_openGL->setModel(model);
      mainwindow->ui->OpenGLWidget->show();
      mainwindow->ui->ScaleEdit->show();
      mainwindow->ui->TransformEditX->show();
      mainwindow->ui->TransformEditY->show();
      mainwindow->ui->TransformEditZ->show();
      mainwindow->ui->RotateEditX->show();
      mainwindow->ui->RotateEditY->show();
      mainwindow->ui->RotateEditZ->show();
      m_openGL->LoadSettings();
      mainwindow->updateUIFromModel();
      m_openGL->update();
      mainwindow->showModelInfo();
    }
  }
}
}  // namespace s21
