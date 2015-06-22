#pragma once
#include <QGLViewer/qglviewer.h>
#include "actor.h"
#include "vector"
class Viewport : public QGLViewer
{
public:
    Viewport(QWidget *parent);
    void draw();
    void init();
    std::vector<Actor*> _drawables;

};
