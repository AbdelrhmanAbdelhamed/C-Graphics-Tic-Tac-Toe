#include "point.h"
#include "cross.h"
#include "graphics.h"

Cross::Cross() {
}

Cross::Cross(int length) {
    this->length = length;
}
/**
 * Draw a cross shape with using two lines with the same values for y but opposite x values.
 * It uses the length attribute to determine the size of the shape.
 * @param point center point to start drawing with it.
 * @param color
 * @param thickness
 */
void Cross::draw(Point point, int color, int thickness) {
    setcolor(color);
    setlinestyle(SOLID_LINE, 1, thickness);

    line(point.x - length, point.y - length, point.x + length, point.y + length);
    line(point.x + length, point.y - length, point.x - length, point.y + length);

}
