#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int WIDTH = 10;   // Width of the minefield
const int HEIGHT = 10;  // Height of the minefield
const int MINES = 10;   // Number of mines

struct Cell {
    bool isMine = false;
    bool isRevealed = false;
    bool isFlagged = false;
    int adjacentMines = 0;
};

vector<vector<Cell>> minefield(HEIGHT, vector<Cell>(WIDTH));

void clearScreen() {
#if defined(_WIN32) || defined(_WIN64)
    system("CLS");
#else
    system("clear");
#endif
}

void generateMinefield() {
    srand(time(0));
    int minesPlaced = 0;
    while (minesPlaced < MINES) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        if (!minefield[y][x].isMine) {
            minefield[y][x].isMine = true;
            minesPlaced++;
        }
    }

    // Calculate adjacent mines
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if (minefield[y][x].isMine) continue;
            int count = 0;
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    int nx = x + i;
                    int ny = y + j;
                    if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT && minefield[ny][nx].isMine) {
                        count++;
                    }
                }
            }
            minefield[y][x].adjacentMines = count;
        }
    }
}

void printMinefield(bool revealAll = false) {
    clearScreen();
    cout << "    >>~< Minesweeper >~<<" << endl << endl;

    // Print column numbers
    cout << "    ";
    for (int x = 0; x < WIDTH; ++x) cout << " " << x % 10 << " ";
    cout << endl;

    for (int y = 0; y < HEIGHT; ++y) {
        // Print row numbers
        cout << " " << y % 10 << " ";

        for (int x = 0; x < WIDTH; ++x) {
            if (revealAll) {
                if (minefield[y][x].isMine) cout << " * ";
                else if (minefield[y][x].adjacentMines > 0) cout << " " << minefield[y][x].adjacentMines << " ";
                else cout << " . ";
            } else {
                if (minefield[y][x].isRevealed) {
                    if (minefield[y][x].isMine) cout << " * ";
                    else if (minefield[y][x].adjacentMines > 0) cout << " " << minefield[y][x].adjacentMines << " ";
                    else cout << " . ";
                } else if (minefield[y][x].isFlagged) {
                    cout << " F ";
                } else {
                    cout << " # ";
                }
            }
        }
        cout << endl;
    }
}

void revealCell(int x, int y) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT || minefield[y][x].isRevealed) return;

    minefield[y][x].isRevealed = true;

    if (minefield[y][x].adjacentMines == 0) {
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                revealCell(x + i, y + j);
            }
        }
    }
}

bool isWin() {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if (!minefield[y][x].isMine && !minefield[y][x].isRevealed) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    generateMinefield();

    while (true) {
        printMinefield();
        int x, y;
        char action;
        cout << "\nEnter command (r x y to reveal, f x y to flag): ";
        cin >> action >> x >> y;

        if (action == 'r') {
            if (minefield[y][x].isMine) {
                printMinefield(true);
                cout << "\nYou hit a mine! Game over.\n";
                break;
            }
            revealCell(x, y);
            if (isWin()) {
                printMinefield(true);
                cout << "\nCongratulations! You won.\n";
                break;
            }
        } else if (action == 'f') {
            minefield[y][x].isFlagged = !minefield[y][x].isFlagged;
        }
    }

    return 0;
}
