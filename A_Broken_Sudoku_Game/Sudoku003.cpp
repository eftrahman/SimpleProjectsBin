#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const int SIZE = 9;
const int SUBGRID_SIZE = 3;

void clearScreen() {
#if defined(_WIN32) || defined(_WIN64)
    system("CLS");
#else
    system("clear");
#endif
}

class Sudoku {
private:
    vector<vector<int>> board;
    vector<vector<int>> solution;

    bool isSafe(int row, int col, int num) {
        for (int x = 0; x < SIZE; x++) {
            if (board[row][x] == num || board[x][col] == num || 
                board[row - row % SUBGRID_SIZE + x / SUBGRID_SIZE][col - col % SUBGRID_SIZE + x % SUBGRID_SIZE] == num) {
                return false;
            }
        }
        return true;
    }

    bool solveSudoku(vector<vector<int>>& board) {
        int row, col;
        if (!findUnassignedLocation(board, row, col)) {
            return true; // puzzle solved
        }
        for (int num = 1; num <= SIZE; num++) {
            if (isSafe(row, col, num)) {
                board[row][col] = num;
                if (solveSudoku(board)) {
                    return true;
                }
                board[row][col] = 0;
            }
        }
        return false;
    }

    bool findUnassignedLocation(vector<vector<int>>& board, int& row, int& col) {
        for (row = 0; row < SIZE; row++) {
            for (col = 0; col < SIZE; col++) {
                if (board[row][col] == 0) {
                    return true;
                }
            }
        }
        return false;
    }

    void printGrid(const vector<vector<int>>& grid) {
        clearScreen();
        cout << "   ";
        for (int i = 0; i < SIZE; ++i) {
            cout << " " << i + 1 << " ";
        }
        cout << endl;
        for (int row = 0; row < SIZE; row++) {
            if (row % SUBGRID_SIZE == 0) {
                cout << "  +";
                for (int i = 0; i < SIZE; ++i) {
                    cout << "---+";
                }
                cout << endl;
            }
            cout << row + 1 << " |";
            for (int col = 0; col < SIZE; col++) {
                if (grid[row][col] == 0) {
                    cout << "   |";
                } else {
                    cout << " " << grid[row][col] << " |";
                }
            }
            cout << endl;
        }
        cout << "  +";
        for (int i = 0; i < SIZE; ++i) {
            cout << "---+";
        }
        cout << endl;
    }

    void generatePuzzle() {
        vector<int> base(SIZE);
        iota(base.begin(), base.end(), 1);
        random_shuffle(base.begin(), base.end());
        
        for (int i = 0; i < SIZE; ++i) {
            board[i][(i * SUBGRID_SIZE + i / SUBGRID_SIZE) % SIZE] = base[i];
        }
        
        solveSudoku(board);
        solution = board;

        int blanks = SIZE * SIZE / 2;
        while (blanks > 0) {
            int row = rand() % SIZE;
            int col = rand() % SIZE;
            if (board[row][col] != 0) {
                board[row][col] = 0;
                blanks--;
            }
        }
    }

public:
    Sudoku() {
        board = vector<vector<int>>(SIZE, vector<int>(SIZE, 0));
        generatePuzzle();
    }

    void play() {
        while (true) {
            printGrid(board);
            cout << "Enter your move (row col num), or '0 0 0' to quit: ";
            int row, col, num;
            cin >> row >> col >> num;
            if (row == 0 && col == 0 && num == 0) {
                break;
            }
            if (row > 0 && row <= SIZE && col > 0 && col <= SIZE && num > 0 && num <= SIZE) {
                if (solution[row - 1][col - 1] == num) {
                    board[row - 1][col - 1] = num;
                } else {
                    cout << "Incorrect move!" << endl;
                    cin.ignore();
                    cin.get();
                }
            } else {
                cout << "Invalid input!" << endl;
                cin.ignore();
                cin.get();
            }

            if (isCompleted()) {
                printGrid(board);
                cout << "Congratulations! You have completed the puzzle." << endl;
                break;
            }
        }
    }

    bool isCompleted() {
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                if (board[row][col] == 0) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    srand(time(0));
    Sudoku game;
    game.play();
    return 0;
}
