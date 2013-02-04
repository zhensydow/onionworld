//------------------------------------------------------------------------------
#include <cstdlib>

#include <QtGui/QApplication>

#include "mainwindow.h"

//------------------------------------------------------------------------------
int main(int argc, char **argv ){
  QApplication app(argc, argv);

  MainWindow window;
  //GLWidget window;

  //window.resize( 320, 320 );
  window.show();

  return app.exec();
}

//------------------------------------------------------------------------------
