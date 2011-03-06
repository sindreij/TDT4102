#include <exception>

class OutOfBoundsException: public std::exception {
    virtual const char* what() const throw() {
        return "Out of Bounds";
    }
};

/*
 * Siden jeg liker å tenke på en grid som nettopp en .. grid, så
 * lager jeg like gjerne en egen klasse for nettopp det.
 * Så jeg slipper å tenke på en tabell av tabeller som en grid
 */

class IntGrid {
private:
    int width;
    int height;
    int **grid;
public:
    IntGrid(int width, int height);
    void setCell(int x, int y, int value);
    int getCell(int x, int y);
    int getWidth();
    int getHeight();
    void cleanUpMemory();
};

class Minesweeper {
private:
    int height;
    int width;
    int mines;
    int open;
    IntGrid *board;
    IntGrid *mask;

    void getInput();
    void makeBoard();
    void incrementIfNotMine(int x, int y);
    void placeMines();
    void toggleFlag(int x, int y);
    bool openSquare(int x, int y);
    void printBoard(bool showMines);
    void cleanUpMemory();
    bool checkForVictory();

public:
    void play();

};
