#include "minesweeper.h"
#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;

void Minesweeper::getInput() {
    do {
        cout << "What is the height of the bord. This must be greater than 2" << endl;
        cout << "> ";
        cin >> height;
    } while (height < 2);

    cout << endl;

    do {
        cout << "What is the width of the bord. This must be greater than 2" << endl;
        cout << "> ";
        cin >> width;
    } while (width < 2);

    do {
        cout << "How many mines. It must be greater than 1 and less then " << (height*width)/2 << endl;
        cout << "> ";
        cin >> mines;
    } while ((mines < 1) || (mines >= (height*width)/2));
}

void Minesweeper::makeBoard() {
    board = new IntGrid(width, height);
    mask = new IntGrid(width, height);
    for (int x = 0; x<width; x++) {
        for (int y = 0; y<height; y++) {
            board->setCell(x,y,0);
            mask->setCell(x,y,0);
        }
    }
}

void Minesweeper::incrementIfNotMine(int x, int y) {
    if (x < width && y < height && x >= 0 && y >= 0 && board->getCell(x,y) != -1) {
        board->setCell(x,y, board->getCell(x,y)+1);
    }
}

void Minesweeper::placeMines() {
    srand(time(0));
    for (int i=0; i<mines; i++) {
        int x,y;
        /*
         * Ikke den mest effektive metoden å gjøre det på,
         * men den fungerer...
         */
        do {
            x = rand() % width;
            y = rand() % height;
        } while (board->getCell(x,y) == -1);
        board->setCell(x,y,-1);
        
        //Øker alle naboruter med èn
        incrementIfNotMine(x-1,y-1);
        incrementIfNotMine(x,  y-1);
        incrementIfNotMine(x+1,y-1);
        incrementIfNotMine(x-1,y);
        incrementIfNotMine(x+1,y);
        incrementIfNotMine(x-1,y+1);
        incrementIfNotMine(x  ,y+1);
        incrementIfNotMine(x+1,y+1);
    }
}

void Minesweeper::toggleFlag(int x, int y) {
    if (x < width && y < height) {
        int oldMask = mask->getCell(x,y);
        if (oldMask == 0) {
            mask->setCell(x,y,2);
        } else if (oldMask == 2) {
            mask->setCell(x,y,0);
        }
    }
}

bool Minesweeper::openSquare(int x, int y) {
    if (x < width && y < height && x >= 0 && y >= 0 && mask->getCell(x,y) == 0) {
        mask->setCell(x,y,1);
        if (board->getCell(x,y) == -1) {
            return true;
        }
        if (board->getCell(x,y) == 0) {
            //Litt rekursjonsmagi for å åpne alle naboruter hvis
            //de ikke inneholder miner
            openSquare(x-1,y-1);
            openSquare(x,  y-1);
            openSquare(x+1,y-1);
            openSquare(x-1,y);
            openSquare(x+1,y);
            openSquare(x-1,y+1);
            openSquare(x  ,y+1);
            openSquare(x+1,y+1);
        }
            
    }
    return false;
}

void Minesweeper::printBoard(bool showMines) {
    /*
     * Lukket rute: '#'
     * Lukket rute med flagg: 'F'
     * Åpen rute: '0'
     * Åpen rute med mine i naborute: '5'
     * Mine: X
     */
    //for å markere kolonner;
    cout << "  ";
    for (int x = 0; x< width; x++) {
        cout << x << " ";
    }
    cout << endl;
    
    for (int y = 0; y<height; y++) {
        //Markere rader
        cout << y << " ";
        for (int x = 0; x<width; x++) {
            if (showMines && board->getCell(x,y) == -1) {
                cout << 'X';
            } else {
                int count;
                switch (mask->getCell(x,y)) {
                case 0:
                    cout << '#';
                    break;
                case 1:
                    count = board->getCell(x,y);
                    //Er det 0 miner hos naboene, så lar vi det like gjerne være en tom rute
                    if (count == 0) {
                        cout << ' ';
                    } else {
                        cout << count;
                    }
                    break;
                case 2:
                    cout << "F";
                    break;
                }
            }
            //En space mellom hver rute får det til å bli mer oversiktelig
            cout << " ";
        }
        //ny linje
        cout << endl;
    }
}

void Minesweeper::cleanUpMemory() {
    board->cleanUpMemory();
    mask->cleanUpMemory();
    delete board;
    delete mask;
    board = 0;
    mask = 0;
}

bool Minesweeper::checkForVictory() {
    for (int x = 0; x<width; x++) {
        for (int y = 0; y<height; y++) {
            int boardCell = board->getCell(x,y);
            int maskCell = mask->getCell(x,y);
            if (boardCell != -1 && maskCell != 1) {
                return false;
            }
        }
    }
    return true;
}


void Minesweeper::play() {
    bool isPlaying = true;
    while (isPlaying) {
        getInput();
        makeBoard();
        placeMines();
        bool victory = false;
        bool finished = false;
        while (!finished) {
            printBoard(false);
            cout << "1) Toggle flag, 2) Open, 0) Exit" << endl;
            cout << "(1,2,0) > ";
            int input;
            cin >> input;
            int row, col;
            if (input == 1 || input == 2) {
                cout << "Where?" << endl;
                cout << "row > ";
                cin >> row;
                cout << "col > ";
                cin >> col;
            }
            switch (input) {
                case 1:
                    toggleFlag(col,row);
                    break;
                case 2:
                    if (openSquare(col,row)) {
                        victory = false;
                        finished = true;
                    }
                    break;
                case 0:
                    victory = false;
                    finished = true;
                    break;
            }
            if (checkForVictory()) {
                victory = true;
                break;
            }
        }
        printBoard(true);
        if (victory) {
            cout << "Congratulations! You WON!!!!" << endl;
        } else {
            cout << "You lost" << endl;
        }
        cleanUpMemory();
        cout << "Do you want to play again? (Y/N) > ";
        char answear;
        cin >> answear;
        if (tolower(answear) == 'n') {
            isPlaying = false;
        }
    }
}


/*
 * Grid er en tabell (kolonne) som består av pekere til tabeller (rader).
 * x er radindex, y er kolonneindex
 *
 */

IntGrid::IntGrid(int width, int height) {
    this->width = width;
    this->height = height;
    grid = new int*[height];
    for (int i = 0; i<height; i++) {
        grid[i] = new int[width];
    }
}

int IntGrid::getHeight() {
    return height;
}

int IntGrid::getWidth() {
    return width;
}


int IntGrid::getCell(int x, int y) {
    if (x < width && y < height) {
        return grid[y][x];
    } else {
        throw OutOfBoundsException();
    }
}
void IntGrid::setCell(int x, int y, int value) {
    if (x < width && y < height) {
        grid[y][x] = value;
    } else {
        throw OutOfBoundsException();
    }
}

/*
 * Dette burde vært i destructor, men gjør det slik siden oppgaven
 * sier det er slik det skal gjøres.
 */
void IntGrid::cleanUpMemory() {
    for (int i = 0; i<height; i++) {
        delete [] grid[i];
        grid[i] = 0;
    }
    delete [] grid;
    grid = 0;
}
