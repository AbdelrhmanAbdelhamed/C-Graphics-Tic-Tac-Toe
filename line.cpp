#include "line.h"
#include "graphics.h"

Line::Line() {
}

Line::Line(Point startPoint, Point endPoint) {
    this->startPoint = startPoint;
    this->endPoint = endPoint;
    this->setType();
}

void Line::setType() {
    if (startPoint.x == endPoint.x) {
        this->type = Line::TYPE::VERTICAL;
    } else if (startPoint.y == endPoint.y) {
        this->type = Line::TYPE::HORIZONTAL;
    }
}

void Line::draw(int color, int thickness) {
    setcolor(color);
    setlinestyle(SOLID_LINE, 1, thickness);

    line(startPoint.x, startPoint.y, endPoint.x, endPoint.y);
}

