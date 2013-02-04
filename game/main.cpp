//------------------------------------------------------------------------------
#include <cstdlib>

#include <QtGui/QApplication>

#include "game/glwidget.h"

//------------------------------------------------------------------------------
int main(int argc, char **argv ){
  QApplication app(argc, argv);

  GLWidget window;

  window.resize( 320, 320 );
  window.show();

  return app.exec();
}

//------------------------------------------------------------------------------
