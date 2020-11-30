#include "trackball.h"
//Classe que define as operações da trackball do mouse

//Construtor da classe
TrackBall::TrackBall() : rad2deg(180.0 / M_PI)
{
    velocity = 0.0;
    trackingMouse = false;
    lastTime = QTime::currentTime();
}

//Método que lida com o movimento do mouse
void TrackBall::mouseMove(const QPointF &p)
{
    if (!trackingMouse)
        return;

    QTime currentTime = QTime::currentTime();
    int msecs = lastTime.msecsTo(currentTime);
    if (msecs)
    {
        QVector3D vp = mousePosTo3D(p);
        QVector3D currentPos3D = QVector3D(vp.x(), vp.y(), 0.0);
        double lenSqr = currentPos3D.lengthSquared();
        (lenSqr >= 1.0) ? currentPos3D.normalize() : currentPos3D.setZ(sqrt(1.0 - lenSqr));
        axis = QVector3D::crossProduct(lastPos3D, currentPos3D);
        double angle = rad2deg * axis.length();
        velocity = angle / msecs;
        axis.normalize();
        rotation = QQuaternion::fromAxisAndAngle(axis, angle) * rotation;
        lastPos3D = currentPos3D;
        lastTime = currentTime;
    }
}

//Método que lida com o pressionamento do mouse
void TrackBall::mousePress(const QPointF &p)
{
    rotation = getRotation();
    trackingMouse = true;
    lastTime = QTime::currentTime();
    lastPos3D = mousePosTo3D(p);
    double lenSqr = lastPos3D.lengthSquared();
    (lenSqr >= 1.0) ? lastPos3D.normalize() : lastPos3D.setZ(sqrt(1.0 - lenSqr));
    velocity = 0.0;
}

//Método que lida com a liberação do mouse
void TrackBall::mouseRelease(const QPointF &p)
{
    mouseMove(p);
    trackingMouse = false;
}

//Método que lida com o redimensionamento
void TrackBall::resizeViewport(int width, int height)
{
    viewportWidth = static_cast<double>(width);
    viewportHeight = static_cast<double>(height);
}

//Método que pega a rotação do mouse
QQuaternion TrackBall::getRotation()
{
    if (trackingMouse)
        return rotation;
    QTime currentTime = QTime::currentTime();
    double angle = velocity * lastTime.msecsTo(currentTime);
    return QQuaternion::fromAxisAndAngle(axis, angle) * rotation;
}

//Método que converte a posição do mouse para a cena 3D
QVector3D TrackBall::mousePosTo3D(const QPointF &p)
{
    return QVector3D(2.0 * p.x() / viewportWidth - 1.0, 1.0 - 2.0 * p.y() / viewportHeight, 750.0);
}
