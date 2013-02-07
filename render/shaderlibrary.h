//------------------------------------------------------------------------------
#ifndef RENDER_SHADERLIBRARY_H
#define RENDER_SHADERLIBRARY_H
//------------------------------------------------------------------------------

#include "version.h"

#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1
#include <GL/gl.h>
#include <GL/glu.h>

namespace Render{
    class ShaderLibrary {
    public:
        static ShaderLibrary * instance();

        ShaderLibrary(const ShaderLibrary&) = delete;
        ShaderLibrary& operator=(const ShaderLibrary&) = delete;

        void initialize();
        void setPath( const std::string & path );

        GLuint getProgram( const std::string & name ) const;

    private:
        ShaderLibrary();

        static ShaderLibrary * s_singleton;

        Version version;
        std::string path;
    };

    inline ShaderLibrary::ShaderLibrary(){
        // empty
    }

    inline ShaderLibrary * ShaderLibrary::instance(){
        if( 0 == s_singleton ){
            s_singleton = new ShaderLibrary();
        }

        return s_singleton;
    }
}

//------------------------------------------------------------------------------
#endif//RENDER_SHADERLIBRARY_H

//------------------------------------------------------------------------------
