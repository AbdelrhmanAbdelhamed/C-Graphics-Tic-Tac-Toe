#include <iostream>
#include <windows.h>

#include "graphics.h"
#include "line.h"
#include "grid.h"
#include "shape.h"
#include "cross.h"
#include "circle.h"

using namespace std;

int main() {
    /////////////////////////Configuration Variables////////////////////////////
    int const SCREEN_WIDTH = GetSystemMetrics(SM_CXSCREEN);
    int const SCREEN_HEIGHT = GetSystemMetrics(SM_CYSCREEN);

    // display a full screen window
    initwindow(SCREEN_WIDTH, SCREEN_HEIGHT);

    Point const SCREEN_CENTER_POINT = Point(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

    int const CELL_CENTER_POINT_DISTANCE = 100;
    // int const CELL_CENTER_POINT_DISTANCE = 50;

    int const PLAYER_ONE_COLOR = BLUE;
    // int const PLAYER_ONE_COLOR = YELLOW;
    int const PLAYER_ONE_SHAPE_SIZE = 70;
   // int const PLAYER_ONE_SHAPE_SIZE = 30;

    int const PLAYER_TWO_COLOR = RED;
    int const PLAYER_TWO_SHAPE_SIZE = 70;
    // int const PLAYER_TWO_SHAPE_SIZE = 30;
    /////////////////////////Configuration Variables////////////////////////////

    settextstyle(COMPLEX_FONT, HORIZ_DIR, 6);

    Player players[] = {
        Player('X', PLAYER_ONE_COLOR, new Cross(PLAYER_ONE_SHAPE_SIZE)),
        Player('O', PLAYER_TWO_COLOR, new Circle(PLAYER_TWO_SHAPE_SIZE))
    };

    /**
     * You could use any combinations of four Line's Points to form a perfect equal grid 
     * I managed to do so by rearrange the lines then sorting them to maintain the same order no matter what
     * You could also use SCREEN_CENTER_POINT (+/- x/y) to draw the grid relative to the center
     */
    Line lines[4] = {
        Line(Point(300, 300), Point(900, 300)), // Horizontal line equation: y = 300 
        Line(Point(500, 100), Point(500, 700)), // Vertical line equation: x = 500
        Line(Point(300, 500), Point(900, 500)), // Horizontal line equation: y = 500
        Line(Point(700, 100), Point(700, 700)) // Vertical line equation: x = 700

        /*Line(Point(SCREEN_CENTER_POINT.x + 50, SCREEN_CENTER_POINT.y - 150), Point(SCREEN_CENTER_POINT.x + 50, SCREEN_CENTER_POINT.y + 150)),
        Line(Point(SCREEN_CENTER_POINT.x - 50, SCREEN_CENTER_POINT.y - 150), Point(SCREEN_CENTER_POINT.x - 50, SCREEN_CENTER_POINT.y + 150)),
        Line(Point(SCREEN_CENTER_POINT.x - 150, SCREEN_CENTER_POINT.y - 50), Point(SCREEN_CENTER_POINT.x + 150, SCREEN_CENTER_POINT.y - 50)),
        Line(Point(SCREEN_CENTER_POINT.x - 150, SCREEN_CENTER_POINT.y + 50), Point(SCREEN_CENTER_POINT.x + 150, SCREEN_CENTER_POINT.y + 50))*/
    };

    Grid grid = Grid(lines, players);
    // display the game board and turn text for the first time
    grid.draw();

    int turn = 0;
    char turnText[21] = " 's turn     ";
    turnText[0] = players[turn].letter;
    setcolor(players[turn].color);
    outtextxy(10, 10, turnText);

    int mouseX, mouseY;
    while (true) {
        getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);
        if ((mouseX > lines[0].startPoint.x) && (mouseX < lines[2].endPoint.x)
                && (mouseY > lines[1].startPoint.y) && (mouseY < lines[3].endPoint.y)) {

            int cellNumber = grid.getCellNumber(Point(mouseX, mouseY));
            if (cellNumber >= 1 && cellNumber <= 9) {

                if (grid.assignBoardLetter(cellNumber, players[turn])) {
                    Point cellCenterPoint = grid.getCellCenterPoint(cellNumber, CELL_CENTER_POINT_DISTANCE);
                    players[turn].play(cellCenterPoint);

                    grid.checkWinner();
                    bool isComplete = grid.isComplete();
                    bool isOver = grid.isOver();

                    if (isOver || isComplete) {
                        if (isOver) {
                            if (players[0].isWinner) {
                                setcolor(players[0].color);
                                outtextxy(10, 10, "Player X WON!");
                            } else if (players[1].isWinner) {
                                setcolor(players[1].color);
                                outtextxy(10, 10, "Player O WON!");
                            }
                        } else if (isComplete) { // if neither players is a winner and it is complete then it has to be draw!
                            setcolor(WHITE);
                            outtextxy(10, 10, "DRAW!        ");
                        }
                        turn = 0;
                        grid.resetGame(2000);
                        grid.draw();
                    } else {
                        turn = ++turn % 2;
                    }

                    turnText[0] = players[turn].letter;
                    setcolor(players[turn].color);
                    outtextxy(10, 10, turnText);

                } else {
                    outtextxy(10, 10, "Invalid Move!");
                }
            }
        }
        delay(100);
    }
}