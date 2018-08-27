#include "graphics.h"

#include "player.h"
#include "shape.h"

Player::Player() {
}

Player::Player(char letter, int color, Shape *shape, bool isWinner) {
    this->letter = letter;
    this->color = color;
    this->isWinner = isWinner;
    this->shape = shape;
}

void Player::play(Point point) {
    this->shape->draw(point, color);
}
