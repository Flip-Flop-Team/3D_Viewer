#include "camera.h"

//Classe que define a posição da câmera
Camera::Camera()
{
    eye = QVector3D(0.0, 0.0, 1.0);
    at = QVector3D(0.0, 0.0, 0.0);
    up = QVector3D(0.0, 1.0, 0.0);
}
