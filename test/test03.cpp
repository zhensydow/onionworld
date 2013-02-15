//------------------------------------------------------------------------------
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include "common/SVGPathParser.h"

//------------------------------------------------------------------------------
int main(int argc, char **argv ){
    Common::SVGPathParser pp;

    pp.parse( "m108.29,203.8,508.86,0,0,394.28-508.86,0z" );

    if( pp.failed() ){
        std::cout << "parse fail\n";
    }else{
        std::cout << "parse ok\n";
    }

    return EXIT_SUCCESS;
}

//------------------------------------------------------------------------------
