//------------------------------------------------------------------------------
#ifndef GLWIDGET_H
#define GLWIDGET_H

//------------------------------------------------------------------------------
#include <QtOpenGL/QGLWidget>

namespace Render{
  class Render;
}

//------------------------------------------------------------------------------
class GLWidget : public QGLWidget {
 public:
  GLWidget(QWidget *parent = NULL);
  void initializeGL();
  void resizeGL(int w, int h);

 protected:

 private:
  Q_OBJECT
	Render::Render * render;
};

//------------------------------------------------------------------------------
#endif//GLWIDGET_H

//------------------------------------------------------------------------------
