//------------------------------------------------------------------------------
#ifndef COMMON_SVGLEVELREADER_H
#define COMMON_SVGLEVELREADER_H

//------------------------------------------------------------------------------
#include "tinyxml2/tinyxml2.h"

//------------------------------------------------------------------------------
namespace Common{
    using namespace tinyxml2;

    /** Class used to get Level data from svg file.

        <b>Visitor pattern</b> class that accept xml data from a SVG file and
        load in memory as level data.

        @ingroup Common 
    */
    class SVGLevelReader : public XMLVisitor{
    public:
        bool VisitEnter( const XMLDocument & doc );
        bool VisitExit( const XMLDocument & doc );
        bool VisitEnter( const XMLElement & el, const XMLAttribute * att );
        bool VisitExit( const XMLElement & el );
        bool Visit (const XMLDeclaration & dec );
        bool Visit (const XMLText & txt );
        bool Visit (const XMLComment & c );
        bool Visit (const XMLUnknown & uk );
    };
}

//------------------------------------------------------------------------------
#endif//COMMON_SVGLEVELREADER_H

//------------------------------------------------------------------------------
