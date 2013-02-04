//------------------------------------------------------------------------------
#include "shaderlibrary.h"

#include <boost/format.hpp>

#include "render/shaders.h"

//------------------------------------------------------------------------------
namespace Render{
    ShaderLibrary * ShaderLibrary::s_singleton = 0;

    void ShaderLibrary::initialize(){
        std::string sv(reinterpret_cast<const char*>(glGetString( GL_SHADING_LANGUAGE_VERSION )));
        this->version = Render::Version( sv );
        if( this->version != Render::Version(1,20) and
            this->version != Render::Version(3,30) ){
            printf( "Invalid shader version: %d.%d\n",
                    this->version.mayor, this->version.minor );

            exit(EXIT_FAILURE);
        }

        this->setPath( "." );
    }
    
    void ShaderLibrary::setPath( const std::string & path ){
        auto fpath = boost::format("%1%/%2%.%3%/")
            % path % this->version.mayor % this->version.minor;
        this->path = fpath.str();
    }

    GLuint ShaderLibrary::getProgram( const std::string & name ) const{
        GLuint program = 0;
        std::vector<GLuint> shaders;

        shaders.push_back( createShader( GL_VERTEX_SHADER, this->path + name + ".vert" ) );
        shaders.push_back( createShader( GL_FRAGMENT_SHADER, this->path + name + ".frag" ) );

        program  = createProgram( shaders );

        std::for_each( shaders.begin(), shaders.end(), glDeleteShader );
        
        return program;
    }
}

//------------------------------------------------------------------------------
