#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QFileDialog>

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = nullptr);

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

signals:

public slots:
    void toggleBackgroundColor(bool toBlack);
    void showFileOpenDialog();
};

#endif // GLWIDGET_H
