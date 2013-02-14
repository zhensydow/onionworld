//------------------------------------------------------------------------------
#include "CBezier.h"

//------------------------------------------------------------------------------
namespace Math{
    Vector2D CBezier::eval( const double & t ) const{
        const double s = 1 - t;
        //b(t) = s^3*p0 + 3*s^2*t*p1 + 3*s*t^2*p2 + t^3*p3
        auto a = p0*(s*s*s);
        auto b = p1*(3.0*s*s*t);
        auto c = p2*(3.0*s*t*t);
        auto d = p3*(t*t*t);
        return a+b+c+d;
    }
}

//------------------------------------------------------------------------------