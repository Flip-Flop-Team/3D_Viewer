#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget(parent)
{

}

void GLWidget::initializeGL()
{
    initializeOpenGLFunctions();
}
void GLWidget::resizeGL(int width , int height)
{
}
void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void GLWidget::toggleBackgroundColor(bool toBlack)
{
    makeCurrent();
    if (toBlack) {
        glClearColor(0, 0, 0, 1);
    } else {
        glClearColor(1, 1, 1, 1);
    }
    update();
}

void GLWidget::showFileOpenDialog()
{
    QByteArray fileFormat = "off";
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this ,
        "Open File",
        QDir::homePath(),
        QString("%1 Files (*.%2)")
        .arg(QString(fileFormat.toUpper()))
        .arg(QString(fileFormat)));
        if (!fileName.isEmpty()) {
            /*readOFFFile(fileName);
            genNormals();
            genTexCoordsCylinder();
            genTangents();
            createVBOs();
            createShaders();
            */
            qDebug("Show");
            update();
      }
}
