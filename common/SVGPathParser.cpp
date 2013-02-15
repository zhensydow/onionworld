//------------------------------------------------------------------------------
#include "SVGPathParser.h"

//------------------------------------------------------------------------------
#include <iostream>
#include "common/debug.h"

//------------------------------------------------------------------------------
namespace Common{
    void SVGPathParser::parse( const std::string & d ){
        isfailed = false;
        sstream << d;

        char c = sstream.get();
        switch( c ){
        case 'm': // relative move
            {
                auto nn = getNumbers();
                for( auto i = nn.begin(); i != nn.end(); ++i ){
                    std::cout << *i << std::endl;
                }
                break;
            }
            
        default:
            oassert( false && "Unknown path type" );
            isfailed = true;
            break;
        }

    }

    //--------------------------------------------------------------------------
    std::vector<double> SVGPathParser::getNumbers(){
        std::vector<double> res; 
        double v;

        while( not sstream.fail() ){
            strip();
            sstream >> v;
            if( not sstream.fail() ){
                res.push_back( v );
            }
        }

        return res;    
    }

    //--------------------------------------------------------------------------
    void SVGPathParser::strip(){
        static const std::string vals{0x20,0x9,0xD,0xA,','};
        char c = sstream.peek();
        while( vals.find(c) != std::string::npos ){
            sstream.get();
            c = sstream.peek();
        }
    }

}

//------------------------------------------------------------------------------
