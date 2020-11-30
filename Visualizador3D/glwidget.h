#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QtGlobal>
#include <QVector4D>
#include <QVector3D>
#include <QVector2D>
#include <QMatrix2x2>
#include <QMatrix4x4>
#include <QOpenGLBuffer>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QTimer>
#include <QElapsedTimer>
#include <QColorDialog>
#include <QColor>
#include <QOpenGLFunctions>
#include <QFileDialog>
#include <QKeyEvent>
#include <QApplication>
#include <iostream>
#include <fstream>
#include <math.h>
#include <limits>

#include "camera.h"
#include "light.h"
#include "material.h"
#include "trackball.h"
#include "mainwindow.h"

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    virtual ~GLWidget();

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent( QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    void keyPressEvent(QKeyEvent *event);

private:
    void readOFFFile(const QString &fileName);
    void genNormals();
    void genTexCoordsCylinder();
    void genTangents();
    void createVBOs();
    void destroyVBOs();
    void createShaders();
    void destroyShaders();

    QPointF pixelPosToViewPos(const QPointF &p);

    unsigned int numVertices;
    unsigned int numFaces;
    QVector4D *vertices;
    QVector3D *normals;
    QVector2D *texCoords;
    QVector4D *tangents;
    std::vector<unsigned int> indices;

    QOpenGLBuffer *vboVertices;
    QOpenGLBuffer *vboNormals;
    QOpenGLBuffer *vboTexCoords;
    QOpenGLBuffer *vboTangents;
    QOpenGLBuffer *vboIndices;

    QOpenGLShader *vertexShader;
    QOpenGLShader *fragmentShader;
    QOpenGLShaderProgram *shaderProgram;
    unsigned int currentShader;
    GLuint texID[2];
    QMatrix4x4 modelViewMatrix;
    QMatrix4x4 projectionMatrix;

    Camera camera;
    Light light;
    Material material;

    TrackBall trackBall;
    double zoom;
    double fpsCounter;
    unsigned int frameCounter;

    QTimer timer;
    QElapsedTimer frameTime;


signals:
    void statusBarMessage(QString ns);
    void fpsChanged(double fps);

public slots:
    void changeBackgroundColor();
    void showFileOpenDialog();
    void animate();
};

#endif // GLWIDGET_H
