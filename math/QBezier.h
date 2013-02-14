#ifndef MATH_QBEZIER_H
#define MATH_QBEZIER_H

#include "Vector2D.h"

namespace Math{
    /** Quadratic Bezier curve
        @ingroup Math
    */
    class QBezier {
    public:
        QBezier( const Vector2D & a, const Vector2D & b, const Vector2D & c );
        Vector2D eval( const double & t ) const;

    private:
        Vector2D p0;
        Vector2D p1;
        Vector2D p2;
    };

    inline QBezier::QBezier( const Vector2D & a, const Vector2D & b, const Vector2D & c )
        : p0{a}, p1{b}, p2{c}
    {
        // empty
    }

}

#endif//MATH_QBEZIER_H
