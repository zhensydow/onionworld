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

    //--------------------------------------------------------------------------
    QBezier CBezier::simplify1() const{
        constexpr double t2 = 0.5 * 0.5;
        auto vt = eval( 0.5 );
        auto px = (vt.x - t2*p0.x - t2*p3.x) / (2.0*t2);
        auto py = (vt.y - t2*p0.y - t2*p3.y) / (2.0*t2);
        return QBezier{p0,{px,py},p3};
    }

}

//------------------------------------------------------------------------------
