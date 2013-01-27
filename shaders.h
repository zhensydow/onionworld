//------------------------------------------------------------------------------
#ifndef SHADERS_H
#define SHADERS_H

//------------------------------------------------------------------------------
#include <string>
#include <vector>

#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1
#include <GL/gl.h>

//------------------------------------------------------------------------------
GLuint CreateShader( GLenum shaderType, const std::string &filename );
GLuint CreateProgram( const std::vector<GLuint> &shaders );

//------------------------------------------------------------------------------
#endif//SHADERS_H

//------------------------------------------------------------------------------
