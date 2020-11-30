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

    unsigned int numVertices; //número de vértices do objeto
    unsigned int numFaces; //número de faces do objeto
    QVector4D *vertices; //vértices do objeto
    QVector3D *normals; //vetores normais do objeto
    QVector2D *texCoords; //coordenadas das texturas do objeto
    QVector4D *tangents; //vetores tangentes das faces do objeto
    std::vector<unsigned int> indices; //vetor que indexa as faces triangulares

    QOpenGLBuffer *vboVertices; //vbo dos vértices
    QOpenGLBuffer *vboNormals; //vbo dos vetores normais
    QOpenGLBuffer *vboTexCoords; //vbo das coordenadas das texturas
    QOpenGLBuffer *vboTangents; //vbo das tangentes
    QOpenGLBuffer *vboIndices; //vbo dos índices

    QOpenGLShader *vertexShader; //shader de transformação de vértices
    QOpenGLShader *fragmentShader; //shader que cria os fragmentos
    QOpenGLShaderProgram *shaderProgram; //programa de shader sendo utilizado no momento, que junta o shader de vértices e fragmentos
    unsigned int currentShader; //inteiro que indica qual shader está sendo utilizado no momento
    GLuint texID[2]; //índices das coordenadas (0 - difusa e 1 - normal)
    QMatrix4x4 modelViewMatrix; //matriz do objeto
    QMatrix4x4 projectionMatrix; //matriz de projeção do objeto

    Camera camera; //informações da câmera
    Light light; //posição e intensidade da luz
    Material material; //informações das características do material do objeto

    TrackBall trackBall; //comunicação entre as informações do mouse e a matriz de projeção
    double zoom; //quantidade de zoom atual
    double fpsCounter; //contador de fps
    unsigned int frameCounter; //contador de quadros para calcular o fps

    QTimer timer; //contador de tempo
    QElapsedTimer frameTime; //timer para calcular o fps


signals:
    void statusBarMessage(QString ns);
    void fpsChanged(double fps);

public slots:
    void changeBackgroundColor();
    void showFileOpenDialog();
    void animate();
};

#endif // GLWIDGET_H
