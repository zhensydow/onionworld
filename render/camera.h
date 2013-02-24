//------------------------------------------------------------------------------
#ifndef CAMERA_H
#define CAMERA_H

//------------------------------------------------------------------------------
#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1
#include <GL/gl.h>

#include <vector>

//------------------------------------------------------------------------------
namespace Render{
    /** Object that sets camera position in shaders.
        @ingroup Render
     */
    class Camera{
    public:
        void init();
        void resize( const int w, const int h );
        void addShader( const GLuint shader );

    private:
        struct CameraShader{
            GLuint shader;
            GLuint offsetUnif;
        };

        float m_offx{0};
        float m_offy{0};

        std::vector<CameraShader> m_shaders;
    };
}

//------------------------------------------------------------------------------
#endif//CAMERA_H

//------------------------------------------------------------------------------
