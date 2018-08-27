/* 
 * File:   circle.h
 * Author: AAGOOGLE
 *
 * Created on April 26, 2018
 */

#ifndef CIRCLE_H
#define CIRCLE_H

#include "graphics.h"

#include "point.h"
#include "shape.h"

struct Circle: Shape {
    int radius;

    Circle();
    Circle(int radius);

    void draw(Point point, int color = GREEN, int thickness = 10);
};

#endif /* CIRCLE_H */

