/* 
 * File:   player.h
 * Author: AAGOOGLE
 *
 * Created on April 26, 2018
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "graphics.h"

#include "shape.h"
#include "point.h"

struct Player {
    char letter;
    int color;
    bool isWinner;
    Shape *shape;

    Player();
    Player(char letter, int color, Shape *shape, bool isWinner = false);

    void play(Point point);
};


#endif /* PLAYER_H */

