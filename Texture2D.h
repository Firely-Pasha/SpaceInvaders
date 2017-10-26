//
// Created by firely-pasha on 6/20/17.
//

#ifndef SPACEINVADERS_TEXURE2D_H
#define SPACEINVADERS_TEXURE2D_H


#include <QtCore/QString>
#include <QOpenGLWidget>
#include <QtGui/QImage>
#include <GL/gl.h>
#include <QtOpenGL/QGLWidget>
#include <QVector2D>

class QImage;

class Texture2D
{
private:
    GLuint textureId;
    QImage glImage;

    int width;
    int height;
    float scale;

public:
    Texture2D(const QString& fileName, const QRect& rect = QRect(0, 0, 0, 0));
    Texture2D(const QImage image);
    virtual ~Texture2D();

    void draw(QVector2D& point);
    int getWidth() const;
    int getHeight();
};



#endif //SPACEINVADERS_TEXURE2D_H
