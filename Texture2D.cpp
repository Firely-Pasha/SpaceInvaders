//
// Created by firely-pasha on 6/20/17.
//

#include "Texture2D.h"
#include <QDebug>

Texture2D::Texture2D(const QString &fileName, const QRect& rect)
{
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);

    QImage originalImage(fileName);
    glImage = QGLWidget::convertToGLFormat(originalImage);

    if (rect.height() != 0 && rect.height() != 0) {
        glImage = glImage.copy(rect);
    }

    glTexImage2D(GL_TEXTURE_2D, 0, 4,
                 glImage.width(), glImage.height(), 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, glImage.bits());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glBindTexture(GL_TEXTURE_2D, 0);

    scale = 1;
    width = glImage.width();
    height = glImage.height();
}

Texture2D::Texture2D(const QImage image)
{
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);

    glImage = image;

    glTexImage2D(GL_TEXTURE_2D, 0, 3,
                 glImage.width(), glImage.height(), 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, glImage.bits());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glBindTexture(GL_TEXTURE_2D, 0);

    scale = 1;
    width = glImage.width();
    height = glImage.height();
}

Texture2D::~Texture2D()
{
}

void Texture2D::draw(QVector2D& point)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glBegin(GL_QUADS);

    float x = point.x();
    float y = point.y();

    glTexCoord2f(1, 0), glVertex2f(x + width  * scale,
                                   y);
    glTexCoord2f(1, 1), glVertex2f(x + width  * scale,
                                   y + height * scale);
    glTexCoord2f(0, 1), glVertex2f(x,
                                   y + height * scale);
    glTexCoord2f(0, 0), glVertex2f(x,
                                   y);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

int Texture2D::getWidth() const
{
    return width;
}

int Texture2D::getHeight()
{
    return height;
}
