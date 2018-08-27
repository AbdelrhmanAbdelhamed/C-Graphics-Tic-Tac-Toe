#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

#include "graphics.h"
#include "grid.h"
#include "player.h"

Grid::Grid(Line *lines, Player *players) {
    this->lines = lines;
    this->players = players;

    sortLines();
}

/**
 * Draw the grid board through drawing two horiz. lines and two verti. lines.
 * @param color
 * @param thickness
 */
void Grid::draw(int color, int thickness) {
    setcolor(color);
    setlinestyle(SOLID_LINE, 1, thickness);

    for (int i = 0; i < 4; i++) {
        lines[i].draw();
    }
}

void Grid::swapLines(int i, int j) {
    Line tempLine = lines[i];
    lines[i] = lines[j];
    lines[j] = tempLine;
}

void Grid::rearrangeLines() {
    bool pickHorizontal = false;
    bool pickVertical = false;
    
    for (int i = 0; i < 4; i++) {
        pickHorizontal = false;
        pickVertical = false;
        
        Line::TYPE currentType = (Line::TYPE) (i % 2);

        if (currentType == Line::TYPE::HORIZONTAL && lines[i].type != Line::TYPE::HORIZONTAL) {
            pickHorizontal = true;
        } else if (currentType == Line::TYPE::VERTICAL && lines[i].type != Line::TYPE::VERTICAL) {
            pickVertical = true;
        } else {
            continue; // do nothing because the line already in the right place
        }
        for (int j = 0; j < 4; j++) {
            if (j == i) {
                continue; // to not compare the same element
            } else if (pickHorizontal && lines[j].type == Line::TYPE::HORIZONTAL ||
                    pickVertical && lines[j].type == Line::TYPE::VERTICAL) {
                swapLines(i, j);
                break;
            }
        }
    }
}

// sorting lines in that ascending order ==> [ HORIZONTAL(Lowest Y), VERTICAL(Lowest X), HORIZONTAL(Highest Y), VERTICAL(Highest X) ]
void Grid::sortLines() {
    rearrangeLines();

    bool doSwap = false;
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            doSwap = false;
            if (lines[i].type == lines[j].type) {
                if (lines[i].type == Line::TYPE::HORIZONTAL) {
                    if (lines[j].startPoint.y < lines[i].startPoint.y) {
                        doSwap = true;
                    }
                } else if (lines[i].type == Line::TYPE::VERTICAL) {
                    if (lines[j].startPoint.x < lines[i].startPoint.x) {
                        doSwap = true;
                    }
                }
                if (doSwap) {
                    swapLines(i, j);
                }
            }
        }
    }

}

bool Grid::isOccupied(char value) {
    return ( value == players[0].letter || value == players[1].letter);
}

// All cells has been marked
bool Grid::isComplete() {
    bool isComplete = true;
    for (int rows = 0; rows < 3; rows++) {
        for (int cols = 0; cols < 3; cols++) {
            if ((board[rows][cols] != players[0].letter) && (board[rows][cols] != players[1].letter)) {
                isComplete = false;
                return isComplete;
            }
        }
    }
    return isComplete;
}

// One of the players has won!
bool Grid::isOver() {
    return ( players[0].isWinner || players[1].isWinner);
}

void Grid::checkDiagonal() {
    if ((board[0][0] == players[0].letter &&
            board[1][1] == players[0].letter &&
            board[2][2] == players[0].letter)
            ||

            (board[0][2] == players[0].letter &&
            board[1][1] == players[0].letter &&
            board[2][0] == players[0].letter)

            ) {
        players[0].isWinner = true;
    } else if ((board[0][0] == players[1].letter &&
            board[1][1] == players[1].letter &&
            board[2][2] == players[1].letter)
            ||

            (board[0][2] == players[1].letter &&
            board[1][1] == players[1].letter &&
            board[2][0] == players[1].letter)

            ) {
        players[1].isWinner = true;
    }
}

void Grid::checkVertical() {
    if ((board[0][0] == players[0].letter &&
            board[1][0] == players[0].letter &&
            board[2][0] == players[0].letter)
            ||

            (board[0][1] == players[0].letter &&
            board[1][1] == players[0].letter &&
            board[2][1] == players[0].letter)
            ||

            (board[0][2] == players[0].letter &&
            board[1][2] == players[0].letter &&
            board[2][2] == players[0].letter)
            ) {
        players[0].isWinner = true;
    } else if ((board[0][0] == players[1].letter &&
            board[1][0] == players[1].letter &&
            board[2][0] == players[1].letter)
            ||

            (board[0][1] == players[1].letter &&
            board[1][1] == players[1].letter &&
            board[2][1] == players[1].letter)
            ||

            (board[0][2] == players[1].letter &&
            board[1][2] == players[1].letter &&
            board[2][2] == players[1].letter)
            ) {
        players[1].isWinner = true;
    }
}

void Grid::checkHorizontal() {
    if ((board[0][0] == players[0].letter &&
            board[0][1] == players[0].letter &&
            board[0][2] == players[0].letter)
            ||

            (board[1][0] == players[0].letter &&
            board[1][1] == players[0].letter &&
            board[1][2] == players[0].letter)
            ||

            (board[2][0] == players[0].letter &&
            board[2][1] == players[0].letter &&
            board[2][2] == players[0].letter)
            ) {
        players[0].isWinner = true;
    } else if ((board[0][0] == players[1].letter &&
            board[0][1] == players[1].letter &&
            board[0][2] == players[1].letter)
            ||

            (board[1][0] == players[1].letter &&
            board[1][1] == players[1].letter &&
            board[1][2] == players[1].letter)
            ||

            (board[2][0] == players[1].letter &&
            board[2][1] == players[1].letter &&
            board[2][2] == players[1].letter)
            ) {
        players[1].isWinner = true;
    }
}

/**
 * It assigns a letter on the backbone 2d-array structure of the game.
 * @param ChosenCellNumber The cell number to be assigned the letter to.
 * @param player The player whose letter is being assigned
 * @return 
 */
bool Grid::assignBoardLetter(int ChosenCellNumber, Player player) {
    int currentCellNumber = 0;
    for (int rows = 2; rows >= 0; rows--) { // start the rows from the end to be equivalent to the drawn graphics grid
        for (int cols = 0; cols < 3; cols++) {
            if (++currentCellNumber == ChosenCellNumber) {
                if (!isOccupied(board[rows][cols])) {
                    board[rows][cols] = player.letter;
                    return true;
                } else {
                    return false;
                }
            }
        }
    }
    return false;
}

void Grid::printBoard() {
    cout << endl;
    for (int rows = 2; rows >= 0; rows--) { // start the rows from the end to be equivalent to the drawn graphics grid
        for (int cols = 0; cols < 3; cols++) {
            cout << " " << board[rows][cols];
        }
        cout << endl;
    }
    cout << endl;
}

void Grid::resetBoard() {
    char board[3][3] = {
        { '1', '2', '3'},
        { '4', '5', '6'},
        { '7', '8', '9'}
    };

    for (int rows = 2; rows >= 0; rows--) { // start the rows from the end to be equivalent to the drawn graphics grid
        for (int cols = 0; cols < 3; cols++) {
            this->board[rows][cols] = board[rows][cols];
        };
    }
}

void Grid::checkWinner() {
    checkHorizontal();
    checkVertical();
    checkDiagonal();
}

void Grid::resetWinner() {
    players[0].isWinner = false;
    players[1].isWinner = false;
}

void Grid::resetGame(int timeout) {
    static vector<string> rounds;
    static int roundNumber = 1;
    char roundText[20];
    char resultText[10];

    if (players[0].isWinner) {
        sprintf(resultText, "%c", players[0].letter);
    } else if (players[1].isWinner) {
        sprintf(resultText, "%c", players[1].letter);
    } else if (isComplete()) { // if neither players is a winner and it is complete then it  has to be draw!
        sprintf(resultText, "%c", 'D');
    }

    sprintf(roundText, "Round %d Result: %s ", roundNumber++, resultText);
    rounds.push_back(roundText);

    resetBoard();
    resetWinner();
    delay(timeout);
    clearviewport();
    cleardevice();

    int roundX = GetSystemMetrics(SM_CYSCREEN) + 100;
    int roundY = 10;
    for (int i = 0; i < rounds.size(); i++) {
        char *roundResults = const_cast<char*> (rounds[i].c_str());

        if (roundResults[16] == 'D') {
            setcolor(WHITE);
        } else if (roundResults[16] == players[0].letter) {
            setcolor(players[0].color);
        } else if (roundResults[16] == players[1].letter) {
            setcolor(players[1].color);
        }

        outtextxy(roundX, roundY, roundResults);
        roundY += 70;
    }
}

/**
 * Determine the clicked cell number using the lines grid x,y boundaries.
 * @param mousePoint
 * @return 
 */
int Grid::getCellNumber(Point mousePoint) {
    if (mousePoint.x > lines[0].startPoint.y && mousePoint.x < lines[1].startPoint.x
            && mousePoint.y > lines[1].startPoint.y && mousePoint.y < lines[0].startPoint.y) {
        return 1;
    } else if (mousePoint.x > lines[1].startPoint.x && mousePoint.x < lines[3].startPoint.x
            && mousePoint.y > lines[1].startPoint.y && mousePoint.y < lines[0].startPoint.y) {
        return 2;
    } else if (mousePoint.x > lines[3].startPoint.x && mousePoint.x < lines[0].endPoint.x
            && mousePoint.y > lines[3].startPoint.y && mousePoint.y < lines[0].startPoint.y) {
        return 3;
    } else if (mousePoint.x > lines[0].startPoint.y && mousePoint.x < lines[1].startPoint.x
            && mousePoint.y > lines[0].startPoint.y && mousePoint.y < lines[2].startPoint.y) {
        return 4;
    } else if (mousePoint.x > lines[1].startPoint.x && mousePoint.x < lines[3].startPoint.x
            && mousePoint.y > lines[0].startPoint.y && mousePoint.y < lines[2].startPoint.y) {
        return 5;
    } else if (mousePoint.x > lines[3].startPoint.x && mousePoint.x < lines[0].endPoint.x
            && mousePoint.y > lines[0].startPoint.y && mousePoint.y < lines[2].startPoint.y) {
        return 6;
    } else if (mousePoint.x > lines[2].startPoint.x && mousePoint.x < lines[1].startPoint.x
            && mousePoint.y > lines[2].startPoint.y && mousePoint.y < lines[1].endPoint.y) {
        return 7;
    } else if (mousePoint.x > lines[1].startPoint.x && mousePoint.x < lines[3].startPoint.x
            && mousePoint.y > lines[2].startPoint.y && mousePoint.y < lines[3].startPoint.x) {
        return 8;
    } else if (mousePoint.x > lines[3].startPoint.x && mousePoint.x < lines[2].endPoint.x
            && mousePoint.y > lines[2].startPoint.y && mousePoint.y < lines[3].startPoint.x) {
        return 9;
    } else {
        return 0;
    }
}

/**
 * Determine the cell center point to start draw the shape with it.
 * It use a distance variable to determine the point away from the boundaries.
 * @param cellNumber
 * @param distance
 * @return 
 */
Point Grid::getCellCenterPoint(int cellNumber, int distance) {
    Point centerPoint;
    switch (cellNumber) {
        case 1:
        {
            centerPoint.x = lines[1].startPoint.x;
            centerPoint.y = lines[0].startPoint.y;
            break;
        }
        case 2:
        {
            centerPoint.x = lines[3].startPoint.x;
            centerPoint.y = lines[0].startPoint.y;
            break;
        }
        case 3:
        {
            centerPoint.x = lines[0].endPoint.x;
            centerPoint.y = lines[0].startPoint.y;
            break;
        }
        case 4:
        {
            centerPoint.x = lines[1].startPoint.x;
            centerPoint.y = lines[2].startPoint.y;
            break;
        }
        case 5:
        {
            centerPoint.x = lines[3].startPoint.x;
            centerPoint.y = lines[2].startPoint.y;
            break;
        }
        case 6:
        {
            centerPoint.x = lines[0].endPoint.x;
            centerPoint.y = lines[2].startPoint.y;
            break;
        }
        case 7:
        {
            centerPoint.x = lines[1].startPoint.x;
            centerPoint.y = lines[1].endPoint.y;
            break;
        }
        case 8:
        {
            centerPoint.x = lines[3].startPoint.x;
            centerPoint.y = lines[3].endPoint.y;
            break;
        }
        case 9:
        {
            centerPoint.x = lines[2].endPoint.x;
            centerPoint.y = lines[3].endPoint.y;
            break;
        }
    }

    centerPoint.x -= distance;
    centerPoint.y -= distance;

    return centerPoint;
}
