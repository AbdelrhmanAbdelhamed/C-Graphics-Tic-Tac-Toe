#include "point.h"
#include "circle.h"
#include "graphics.h"

Circle::Circle() {
}

Circle::Circle(int radius) {
    this->radius = radius;
}

void Circle::draw(Point point, int color, int thickness) {
    setcolor(color);
    setlinestyle(SOLID_LINE, 1, thickness);

    circle(point.x, point.y, radius);
}
