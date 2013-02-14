//------------------------------------------------------------------------------
#ifndef MATH_CBEZIER_H
#define MATH_CBEZIER_H

//------------------------------------------------------------------------------
#include "Vector2D.h"
#include "QBezier.h"

//------------------------------------------------------------------------------
namespace Math{
    /** Cubic Bezier curve
        @ingroup Math
    */
    class CBezier {
    public:
        CBezier( const Vector2D & a, const Vector2D & b, 
                 const Vector2D & c, const Vector2D & d );
        Vector2D eval( const double & t ) const;

        QBezier simplify1() const;

    private:
        Vector2D p0;
        Vector2D p1;
        Vector2D p2;
        Vector2D p3;
    };

    //--------------------------------------------------------------------------
    inline CBezier::CBezier( const Vector2D & a, const Vector2D & b, 
                             const Vector2D & c, const Vector2D & d )
        : p0{a}, p1{b}, p2{c}, p3{d}
    {
        // empty
    }
}

//------------------------------------------------------------------------------
#endif//MATH_CBEZIER_H

//------------------------------------------------------------------------------
