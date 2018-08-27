/* 
 * File:   line.h
 * Author: AAGOOGLE
 *
 * Created on April 26, 2018
 */

#ifndef LINE_H
#define LINE_H

#include "graphics.h"

#include "point.h"
#include "shape.h"

struct Line {

    enum class TYPE {
        HORIZONTAL, VERTICAL
    };

    TYPE type;
    Point startPoint;
    Point endPoint;

    Line();
    Line(Point startPoint, Point endPoint);
    void setType();

    void draw(int color = WHITE, int thickness = 10);
};

#endif /* LINE_H */

