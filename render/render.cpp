#include "render.h"

#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1
#include <GL/gl.h>

namespace Render{
  Render * Render::s_singleton = 0;

  void Render::resize(const int w, const int h){
	glViewport( 0, 0, (GLsizei)w, (GLsizei)h );
  }
}
