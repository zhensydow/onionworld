//------------------------------------------------------------------------------
#include "camera.h"

#include <iostream>

//------------------------------------------------------------------------------
namespace Render{
    //--------------------------------------------------------------------------
    void Camera::init(){
        m_offx = 0;
        m_offy = 0;

        for( auto cs: m_shaders ){
            glUseProgram( cs.shader);
            glUniform2f( cs.offsetUnif, 1.0f, 0.5f );
        }
        glUseProgram( 0 );
    }

    //--------------------------------------------------------------------------
    void Camera::addShader( const GLuint shader ){
        auto offsetUnif = glGetUniformLocation( shader, "offset" );

        CameraShader cs;
        cs.shader = shader;
        cs.offsetUnif = offsetUnif;

        m_shaders.push_back( cs );
    }

    //--------------------------------------------------------------------------
    void Camera::resize( const int w, const int h ){
        
    }
}

//------------------------------------------------------------------------------
