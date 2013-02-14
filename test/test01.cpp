//------------------------------------------------------------------------------
#include <cstdlib>
#include <iostream>

#include "tinyxml2/tinyxml2.h"
#include "common/SVGLevelReader.h"

//------------------------------------------------------------------------------
int main(int argc, char **argv ){
    tinyxml2::XMLDocument doc;
    doc.LoadFile( argv[1] );

    Common::SVGLevelReader  visitor;

    doc.Accept( &visitor );

    return EXIT_SUCCESS;
}

//------------------------------------------------------------------------------
