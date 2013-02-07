//------------------------------------------------------------------------------
#ifndef RENDER_RENDER_H
#define RENDER_RENDER_H

//------------------------------------------------------------------------------
#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1
#include <GL/gl.h>

//------------------------------------------------------------------------------
namespace Render{
  class Render{
  public:
	static Render * instance();

	Render(const Render&) = delete;
	Render& operator=(const Render&) = delete;

    void initialize();
	void resize(const int w, const int h);
    void renderScene() const;

  private:
	Render();

	static Render * s_singleton;

    GLuint shaderProgram;
  };

  inline Render::Render() : shaderProgram(0) {
	// empty
  }

  inline Render * Render::instance(){
	if( 0 == s_singleton ){
	  s_singleton = new Render();
	}

	return s_singleton;
  }
}

//------------------------------------------------------------------------------
#endif//RENDER_RENDER_H

//------------------------------------------------------------------------------
