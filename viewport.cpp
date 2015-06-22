#include "viewport.h"


Viewport::Viewport(QWidget *parent) : QGLViewer(parent)
{

}


void Viewport::draw(){

    for(int i =0;i<_drawables.size();i++){
        _drawables.at(i)->draw();
    }
}

void Viewport::init(){
      glDisable(GL_LIGHTING);
      //setSceneRadius(50);
      setGridIsDrawn();
      this->camera()->setZClippingCoefficient(1.0f);
      this->setForegroundColor(QColor(150,150,150));
      this->setBackgroundColor(QColor(20,20,20));
      this->setSceneRadius(10.0f);
}
