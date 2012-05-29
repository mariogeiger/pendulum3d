#ifndef LINEPATH_H
#define LINEPATH_H

#include <QObject>
#include <QVector3D>
#include <QList>
#include <QtOpenGL/QGLBuffer>
#include <QtOpenGL/QGLShaderProgram>

class LinePath : public QObject
{
public:
    LinePath();

    void addPoint(const QVector3D &p);
    void clear();

    void initializeGL(const QGLContext *context);
    void drawGL();

    void setModel(const QMatrix4x4 &m);
    void setView(const QMatrix4x4 &v);
    void setProjection(const QMatrix4x4 &p);
    void setColor(const QColor &color1, const QColor &color2, GLfloat step);

public:
    QVector<QVector3D> _vertices;

    QGLShaderProgram *_program;

    int _vertexLocation;
    int _modelLocation;
    int _viewLocation;
    int _projectionLocation;
    int _color1Location;
    int _color2Location;
    int _stepLocation;
};

#endif // LINEPATH_H
