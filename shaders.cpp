//------------------------------------------------------------------------------
#include "shaders.h"

#include <GL/glext.h>

//------------------------------------------------------------------------------
GLuint CreateShader(GLenum shaderType, const std::string &filename ){
  GLuint shader = glCreateShader( shaderType ); 
  const char *strFileData = filename.c_str(); 
  glShaderSource( shader, 1, &strFileData, nullptr );
    
  glCompileShader( shader );
    
  GLint status;
  glGetShaderiv( shader, GL_COMPILE_STATUS, &status );
  if (status == GL_FALSE){
    GLint infoLogLength;
    glGetShaderiv( shader, GL_INFO_LOG_LENGTH, &infoLogLength );
        
    GLchar *strInfoLog = new GLchar[infoLogLength + 1];
    glGetShaderInfoLog(shader, infoLogLength, nullptr, strInfoLog);
        
    const char *strShaderType = nullptr;
    switch( shaderType ){
    case GL_VERTEX_SHADER: 
      strShaderType = "vertex"; 
      break;
    case GL_GEOMETRY_SHADER: 
      strShaderType = "geometry"; 
      break;
    case GL_FRAGMENT_SHADER: 
      strShaderType = "fragment"; 
      break;
    }
        
    fprintf( stderr, 
	     "Compile failure in %s shader:\n%s\n", strShaderType, strInfoLog );
    delete[] strInfoLog;
  }

  return shader;
}

//------------------------------------------------------------------------------
GLuint CreateProgram( const std::vector<GLuint> &shaders ){
  GLuint program = glCreateProgram();
    
  for( size_t i = 0; i < shaders.size(); i++ ){
    glAttachShader( program, shaders[i] );
  }
    
  glLinkProgram( program );
    
  GLint status;
  glGetProgramiv( program, GL_LINK_STATUS, &status );
  if( status == GL_FALSE ){
    GLint infoLogLength;
    glGetProgramiv( program, GL_INFO_LOG_LENGTH, &infoLogLength );
        
    GLchar *strInfoLog = new GLchar[infoLogLength + 1];
    glGetProgramInfoLog( program, infoLogLength, nullptr, strInfoLog );
    fprintf( stderr, "Linker failure: %s\n", strInfoLog );
    delete[] strInfoLog;
  }
    
  for( size_t i = 0; i < shaders.size(); i++ ){
    glDetachShader( program, shaders[i] );
  }

  return program;
}

//------------------------------------------------------------------------------
