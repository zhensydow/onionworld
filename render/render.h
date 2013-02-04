//------------------------------------------------------------------------------
#ifndef RENDER_RENDER_H
#define RENDER_RENDER_H

//------------------------------------------------------------------------------
namespace Render{
  class Render{
  public:
	static Render * instance();

	void resize(const int w, const int h);

  private:
	Render();
	Render(const Render &);
	void operator=(const Render &);

	static Render * s_singleton;
  };

  inline Render::Render(){
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
