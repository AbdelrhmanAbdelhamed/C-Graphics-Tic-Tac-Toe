/* 
 * File:   shape.h
 * Author: AAGOOGLE
 *
 * Created on April 26, 2018
 */

#ifndef SHAPE_H
#define SHAPE_H

#include "point.h"

class Shape {
public:
    // pure virtual function.
    virtual void draw(Point point, int color, int thickness = 10) = 0;
};



#endif /* SHAPE_H */

