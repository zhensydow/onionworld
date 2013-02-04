#include "render.h"

#include "config.h"
#include "shaderlibrary.h"

namespace Render{
    Render * Render::s_singleton = 0;

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

    void Render::initialize(){
        ShaderLibrary * sl = ShaderLibrary::instance();
        sl->initialize();
        sl->setPath( g_datapath );

        this->shaderProgram = sl->getProgram( "ex01" );

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

    void Render::resize(const int w, const int h){
        glViewport( 0, 0, (GLsizei)w, (GLsizei)h );
    }

    void Render::renderScene() const{
        glClearColor( 0.2f, 0.0f, 0.0f, 0.0f );
        glClear( GL_COLOR_BUFFER_BIT );

        glUseProgram( this->shaderProgram );

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
    }
}
