/* 
 * File:   cross.h
 * Author: AAGOOGLE
 *
 * Created on April 26, 2018
 */
#ifndef CROSS_H
#define CROSS_H

#include "graphics.h"

#include "shape.h"

struct Cross : Shape {
    int length;

    Cross();
    Cross(int length);

    void draw(Point point, int color = YELLOW, int thickness = 10);
};

#endif /* CROSS_H */

