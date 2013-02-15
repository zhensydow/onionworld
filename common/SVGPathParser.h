//------------------------------------------------------------------------------
#ifndef COMMON_SVGPATH_PARSER_H
#define COMMON_SVGPATH_PARSER_H

//------------------------------------------------------------------------------
#include <string>
#include <sstream>
#include <vector>

//------------------------------------------------------------------------------
namespace Common{
    /** Class to help in Path element parse.
        @ingroup Common
    */
    class SVGPathParser {
    public:
        SVGPathParser();
        
        void parse( const std::string & d );
        bool failed() const;

    private:
        std::vector<double> getNumbers();
        void strip();

        bool isfailed;

        std::stringstream sstream;
    };

    inline SVGPathParser::SVGPathParser() : isfailed{false}{ 
        // empty 
    }

    inline bool SVGPathParser::failed() const{
        return this->isfailed;
    }
}

//------------------------------------------------------------------------------
#endif//COMMON_SVGPATH_PARSER_H

//------------------------------------------------------------------------------
