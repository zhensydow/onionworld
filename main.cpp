//------------------------------------------------------------------------------
#include <cstdlib>

#include <vector>
#include <algorithm>

#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>
#include <GL/glut.h>

#include "shaders.h"

//------------------------------------------------------------------------------
const float vertexPositions[] = {
  0.45f, 0.75f, 0.0f, 1.0f,
  -0.75f, -0.45f, 0.0f, 1.0f,
  -0.75f, 0.75f, 0.0f, 1.0f,

  0.75f, 0.75f, 0.0f, 1.0f,
  0.75f, 0.45f, 0.0f, 1.0f,
  -0.75f, -0.75f, 0.0f, 1.0f,

  0.75f, 0.45f, 0.0f, 1.0f,
  -0.45f, -0.75f, 0.0f, 1.0f,
  -0.75f, -0.75f, 0.0f, 1.0f,

  0.75f, 0.15f, 0.0f, 1.0f,
  0.75f, -0.75f, 0.0f, 1.0f,
  -0.15f, -0.75f, 0.0f, 1.0f,
};

const float vertexColors[] = {
  1.0f, 0.0f, 0.0f, 1.0f,
  0.0f, 1.0f, 0.0f, 1.0f,
  0.0f, 0.0f, 1.0f, 1.0f,

  1.0f, 1.0f, 0.0f, 1.0f,
  1.0f, 1.0f, 0.0f, 1.0f,
  1.0f, 1.0f, 0.0f, 1.0f,

  1.0f, 1.0f, 0.0f, 1.0f,
  1.0f, 1.0f, 0.0f, 1.0f,
  1.0f, 1.0f, 0.0f, 1.0f,

  1.0f, 0.0f, 0.0f, 1.0f,
  0.0f, 1.0f, 0.0f, 1.0f,
  0.0f, 0.0f, 1.0f, 1.0f,
};

GLuint posBufferObject = 0;
GLuint colBufferObject = 0;
GLuint myProgram = 0;

std::string strVertexShader = "ex01.vert";
std::string strFragmentShader = "ex01.frag";

//------------------------------------------------------------------------------
void initializeVertexBuffer(){
  glGenBuffers( 1, &posBufferObject );

  glBindBuffer( GL_ARRAY_BUFFER, posBufferObject );
  glBufferData( GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions,
        GL_STATIC_DRAW );
  glBindBuffer( GL_ARRAY_BUFFER, 0 );

  glGenBuffers( 1, &colBufferObject );

  glBindBuffer( GL_ARRAY_BUFFER, colBufferObject );
  glBufferData( GL_ARRAY_BUFFER, sizeof(vertexColors), vertexColors,
        GL_STATIC_DRAW );
  glBindBuffer( GL_ARRAY_BUFFER, 0 );
}

void initializeProgram(){
  std::vector<GLuint> shaders;

  std::string sv(reinterpret_cast<const char*>(glGetString( GL_SHADING_LANGUAGE_VERSION )));
  if( sv != "1.20" and sv != "3.30" ){
      printf( "Invalid shader version: %s\n", sv.c_str() );
      exit(EXIT_FAILURE);
  }

  shaders.push_back( createShader( GL_VERTEX_SHADER, sv + "/" + strVertexShader ) );
  shaders.push_back( createShader( GL_FRAGMENT_SHADER, sv + "/" + strFragmentShader ) );

  myProgram = createProgram( shaders );

  std::for_each( shaders.begin(), shaders.end(), glDeleteShader );
}

//------------------------------------------------------------------------------
void renderScene(void) {
  glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
  glClear( GL_COLOR_BUFFER_BIT );

  glUseProgram( myProgram );
  glBindBuffer( GL_ARRAY_BUFFER, posBufferObject );
  glVertexAttribPointer( 0, 4, GL_FLOAT, GL_FALSE, 0, 0 );

  glBindBuffer( GL_ARRAY_BUFFER, colBufferObject );
  glVertexAttribPointer( 1, 4, GL_FLOAT, GL_FALSE, 0, 0 );

  glEnableVertexAttribArray( 0 );
  glEnableVertexAttribArray( 1 );

  glDrawArrays( GL_TRIANGLES, 0, 12 );

  glDisableVertexAttribArray( 0 );
  glDisableVertexAttribArray( 1 );
  glUseProgram( 0 );

  glutSwapBuffers();
}

void reshape( int w, int h ){
  glViewport( 0, 0, (GLsizei)w, (GLsizei)h );
}

//------------------------------------------------------------------------------
int main(int argc, char **argv ){
  // init GLUT and create Window
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA );
  glutInitWindowSize( 320, 320 );
  glutCreateWindow( "Onion World" );

  initializeProgram();
  initializeVertexBuffer();

  // register callbacks
  glutDisplayFunc( renderScene );
  glutReshapeFunc( reshape );

  glutMainLoop();

  return EXIT_SUCCESS;
}

//------------------------------------------------------------------------------
