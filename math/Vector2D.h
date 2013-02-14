//------------------------------------------------------------------------------
#ifndef MATH_VECTOR2D_H
#define MATH_VECTOR2D_H

//------------------------------------------------------------------------------
namespace Math{
    class Vector2D{
    public:
        Vector2D( const double &a, const double &b );
        
        Vector2D operator*( const double &a ) const;
        Vector2D operator+( const Vector2D &v ) const;

        double x;
        double y;
    };

    //--------------------------------------------------------------------------
    inline Vector2D::Vector2D( const double &a, const double &b )
        : x{a}, y{b}
    {
        // empty
    }

    //--------------------------------------------------------------------------
    inline Vector2D Vector2D::operator*( const double &a ) const{
        return Vector2D{this->x*a,this->y*a};        
    }
    
    //--------------------------------------------------------------------------
    inline Vector2D Vector2D::operator+( const Vector2D &v ) const{
        return Vector2D{this->x+v.x,this->y+v.y};
    }
}

//------------------------------------------------------------------------------
#endif//MATH_VECTOR2D_H

//------------------------------------------------------------------------------
