//------------------------------------------------------------------------------
#include "glwidget.h"

#include "render/render.h"

//------------------------------------------------------------------------------
GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent) {
  setMouseTracking( true );
  this->render = Render::Render::instance();
}

//------------------------------------------------------------------------------
void GLWidget::initializeGL(){
    this->render->initialize();
}

//------------------------------------------------------------------------------
void GLWidget::resizeGL(int w, int h) {
  this->render->resize( w, h );
}

void GLWidget::paintGL() {
    this->render->renderScene();
}

//------------------------------------------------------------------------------
