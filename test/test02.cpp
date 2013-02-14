//------------------------------------------------------------------------------
#include <cstdlib>
#include <iostream>

#include "math/QBezier.h"
#include "math/CBezier.h"

//------------------------------------------------------------------------------
int main(int argc, char **argv ){
    Math::QBezier qb{{0,0},{10,10},{20,0}};
    Math::CBezier cb{{0,0},{8,8},{15,10},{20,0}};

    auto qbs = cb.simplify1();

    std::cout << "[" << qbs.p0.x << ", " << qbs.p0.y << "] ";
    std::cout << "[" << qbs.p1.x << ", " << qbs.p1.y << "] ";
    std::cout << "[" << qbs.p2.x << ", " << qbs.p2.y << "] ";
    std::cout << std::endl;

    auto ev1 = cb.eval(0.5);
    auto ev2 = qbs.eval(0.5);
    std::cout << ev1.x << "," << ev1.y << "=" << ev2.x << "," << ev2.y << std::endl;
    return EXIT_SUCCESS;
}

//------------------------------------------------------------------------------
