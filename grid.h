/* 
 * File:   grid.h
 * Author: AAGOOGLE
 *
 * Created on April 26, 2018
 */

#ifndef GRID_H
#define GRID_H

#include <string>

#include "line.h"
#include "player.h"

class Grid {
private:
    Line *lines;
    Player *players;
    char board[3][3] = {
        { '1', '2', '3'},
        { '4', '5', '6'},
        { '7', '8', '9'}
    };

public:
    Grid(Line *lines, Player *players);
    void swapLines(int i, int j);
    void rearrangeLines();
    void sortLines();
    void draw(int color = WHITE, int thickness = 10);
    bool isOccupied(char value);
    bool isComplete();
    bool isOver();
    void checkDiagonal();
    void checkVertical();
    void checkHorizontal();
    bool assignBoardLetter(int ChosenCellNumber, Player player);
    void printBoard();
    void resetBoard();
    void resetWinner();
    void resetGame(int timeout);
    void checkWinner();
    int getCellNumber(Point mousePoint);
    Point getCellCenterPoint(int cellNumber, int distance = 100);
};


#endif /* GRID_H */

