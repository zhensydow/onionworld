//------------------------------------------------------------------------------
#include "SVGLevelReader.h"

#include <iostream>

//------------------------------------------------------------------------------
namespace Common{
    using namespace tinyxml2;
    using namespace std;

    //--------------------------------------------------------------------------
    bool SVGLevelReader::VisitEnter( const XMLDocument & doc ){
        cout << "document enter\n";
        return true;
    }

    //--------------------------------------------------------------------------
    bool SVGLevelReader::VisitExit( const XMLDocument & doc ){
        cout << "document exit\n";
        return true;
    }

    //--------------------------------------------------------------------------
    bool SVGLevelReader::VisitEnter( const XMLElement & el, const XMLAttribute * att){
        cout << "element " << el.Name() << " enter\n";
        auto p = att;
        while( p ){
            cout << " attribute " << p->Name() << endl;
            p = p->Next();
        }
        return true;
    }

    //--------------------------------------------------------------------------
    bool SVGLevelReader::VisitExit( const XMLElement & el ){
        cout << "element " << el.Name() << " exit\n";
        return true;
    }

    //--------------------------------------------------------------------------
    bool SVGLevelReader::Visit (const XMLDeclaration & dec ){
        cout << "declaration visit\n";
        return true;
    }

    //--------------------------------------------------------------------------
    bool SVGLevelReader::Visit (const XMLText & txt ){
        cout << "text visit\n";
        return true;
    }

    //--------------------------------------------------------------------------
    bool SVGLevelReader::Visit (const XMLComment & c ){
        cout << "comment visit\n";
        return true;
    }

    //--------------------------------------------------------------------------
    bool SVGLevelReader::Visit (const XMLUnknown & uk ){
        cout << "unknown visit\n";
        return true;
    }
}

//------------------------------------------------------------------------------
