//------------------------------------------------------------------------------
#include <cstdlib>

#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>
#include <GL/glut.h>

#include "render/render.h"

//------------------------------------------------------------------------------
Render::Render * render = 0;

//------------------------------------------------------------------------------
void renderScene(void) {
    render->renderScene();
    glutSwapBuffers();
}

//------------------------------------------------------------------------------
void resize( int w, int h ){
  render->resize( w, h );
}

//------------------------------------------------------------------------------
int main(int argc, char **argv ){
  render = Render::Render::instance();

  // init GLUT and create Window
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA );
  glutInitWindowSize( 320, 320 );
  glutCreateWindow( "Onion World" );

  render->initialize();

  // register callbacks
  glutDisplayFunc( renderScene );
  glutReshapeFunc( resize );

  glutMainLoop();

  return EXIT_SUCCESS;
}

//------------------------------------------------------------------------------
