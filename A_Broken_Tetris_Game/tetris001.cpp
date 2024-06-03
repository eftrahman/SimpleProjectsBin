#include <iostream>
#include <vector>
#include <ctime>
#include <conio.h>

using namespace std;

const int width = 10;
const int height = 20;
const char block = '#';
const char empty = '.';

vector<vector<char>> grid(height, vector<char>(width, empty));

struct Point {
    int x, y;
};

struct Tetromino {
    vector<Point> blocks;
    Point pos;
};

vector<Tetromino> tetrominos = {
    {{ {0, 0}, {1, 0}, {2, 0}, {3, 0} }, {width / 2 - 2, 0}}, // I
    {{ {0, 0}, {1, 0}, {1, 1}, {2, 1} }, {width / 2 - 2, 0}}, // S
    {{ {1, 0}, {2, 0}, {0, 1}, {1, 1} }, {width / 2 - 2, 0}}, // Z
    {{ {0, 0}, {0, 1}, {1, 1}, {2, 1} }, {width / 2 - 2, 0}}, // L
    {{ {2, 0}, {0, 1}, {1, 1}, {2, 1} }, {width / 2 - 2, 0}}, // J
    {{ {0, 0}, {1, 0}, {0, 1}, {1, 1} }, {width / 2 - 1, 0}}, // O
    {{ {1, 0}, {0, 1}, {1, 1}, {2, 1} }, {width / 2 - 2, 0}}  // T
};

Tetromino currentTetromino;

void drawGrid() {
    system("cls");
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            cout << grid[y][x];
        }
        cout << endl;
    }
}

bool isValidMove(Tetromino t, int dx, int dy) {
    for (auto& block : t.blocks) {
        int newX = t.pos.x + block.x + dx;
        int newY = t.pos.y + block.y + dy;
        if (newX < 0 || newX >= width || newY < 0 || newY >= height || grid[newY][newX] == block) {
            return false;
        }
    }
    return true;
}

void placeTetromino() {
    for (auto& block : currentTetromino.blocks) {
        grid[currentTetromino.pos.y + block.y][currentTetromino.pos.x + block.x] = block;
    }
}

void removeFullLines() {
    for (int y = 0; y < height; ++y) {
        bool fullLine = true;
        for (int x = 0; x < width; ++x) {
            if (grid[y][x] == empty) {
                fullLine = false;
                break;
            }
        }
        if (fullLine) {
            grid.erase(grid.begin() + y);
            grid.insert(grid.begin(), vector<char>(width, empty));
        }
    }
}

void rotateTetromino() {
    Tetromino rotated = currentTetromino;
    for (auto& block : rotated.blocks) {
        swap(block.x, block.y);
        block.x = -block.x;
    }
    if (isValidMove(rotated, 0, 0)) {
        currentTetromino = rotated;
    }
}

void gameLoop() {
    while (true) {
        drawGrid();
        if (_kbhit()) {
            char ch = _getch();
            switch (ch) {
                case 'a':
                    if (isValidMove(currentTetromino, -1, 0)) currentTetromino.pos.x--;
                    break;
                case 'd':
                    if (isValidMove(currentTetromino, 1, 0)) currentTetromino.pos.x++;
                    break;
                case 's':
                    if (isValidMove(currentTetromino, 0, 1)) currentTetromino.pos.y++;
                    break;
                case 'w':
                    rotateTetromino();
                    break;
            }
        }
        if (isValidMove(currentTetromino, 0, 1)) {
            currentTetromino.pos.y++;
        } else {
            placeTetromino();
            removeFullLines();
            currentTetromino = tetrominos[rand() % tetrominos.size()];
            if (!isValidMove(currentTetromino, 0, 0)) {
                cout << "Game Over!" << endl;
                break;
            }
        }
        drawGrid();
        _sleep(100);
    }
}

int main() {
    srand(time(0));
    currentTetromino = tetrominos[rand() % tetrominos.size()];
    gameLoop();
    return 0;
}
