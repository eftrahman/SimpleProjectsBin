#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // For system()

enum class PieceType { King, Queen, Rook, Bishop, Knight, Pawn, None };
enum class PieceColor { White, Black, None };

class Piece {
public:
    PieceType type;
    PieceColor color;
    bool hasMoved;

    Piece(PieceType t = PieceType::None, PieceColor c = PieceColor::None)
        : type(t), color(c), hasMoved(false) {}
};

class Board {
private:
    std::vector<std::vector<Piece>> board;

public:
    Board() {
        // Initialize an 8x8 board with no pieces
        board.resize(8, std::vector<Piece>(8));
        setupBoard();
    }

    void setupBoard() {
        // Set up the initial positions of the pieces on the board
        // For simplicity, let's use an 8x8 board initialized with default Piece objects
        for (int i = 0; i < 8; ++i) {
            board[1][i] = Piece(PieceType::Pawn, PieceColor::White);
            board[6][i] = Piece(PieceType::Pawn, PieceColor::Black);
        }

        // Set up the rest of the pieces
        std::vector<PieceType> backRow = {
            PieceType::Rook, PieceType::Knight, PieceType::Bishop, PieceType::Queen,
            PieceType::King, PieceType::Bishop, PieceType::Knight, PieceType::Rook
        };

        for (int i = 0; i < 8; ++i) {
            board[0][i] = Piece(backRow[i], PieceColor::White);
            board[7][i] = Piece(backRow[i], PieceColor::Black);
        }
    }

    Piece getPiece(int x, int y) const {
        if (x >= 0 && x < 8 && y >= 0 && y < 8) {
            return board[y][x];
        }
        return Piece(); // Return an empty piece if out of bounds
    }

    void setPiece(int x, int y, const Piece& piece) {
        if (x >= 0 && x < 8 && y >= 0 && y < 8) {
            board[y][x] = piece;
        }
    }

    void printBoard() const {
        for (const auto& row : board) {
            for (const auto& piece : row) {
                if (piece.type == PieceType::None) {
                    std::cout << ". ";
                } else {
                    char symbol = getPieceSymbol(piece);
                    std::cout << symbol << " ";
                }
            }
            std::cout << std::endl;
        }
    }

    char getPieceSymbol(const Piece& piece) const {
        char symbol = '.';
        switch (piece.type) {
            case PieceType::King:   symbol = piece.color == PieceColor::White ? 'K' : 'k'; break;
            case PieceType::Queen:  symbol = piece.color == PieceColor::White ? 'Q' : 'q'; break;
            case PieceType::Rook:   symbol = piece.color == PieceColor::White ? 'R' : 'r'; break;
            case PieceType::Bishop: symbol = piece.color == PieceColor::White ? 'B' : 'b'; break;
            case PieceType::Knight: symbol = piece.color == PieceColor::White ? 'N' : 'n'; break;
            case PieceType::Pawn:   symbol = piece.color == PieceColor::White ? 'P' : 'p'; break;
            default: break;
        }
        return symbol;
    }
};

class Game {
private:
    Board board;

public:
    void play() {
        // Main game loop
        while (true) {
            clearScreen();
            board.printBoard();
            std::string move;
            std::cout << "Enter your move (e.g., e2e4): ";
            std::cin >> move;

            if (move == "exit") break;

            if (isValidMove(move)) {
                makeMove(move);
            } else {
                std::cout << "Invalid move!" << std::endl;
                std::cin.ignore(); // Clear the input buffer
                std::cin.get(); // Wait for user input to proceed
            }
        }
    }

    bool isValidMove(const std::string& move) const {
        // Implement basic validation for the move
        if (move.length() != 4) return false;
        int fromX = move[0] - 'a';
        int fromY = move[1] - '1';
        int toX = move[2] - 'a';
        int toY = move[3] - '1';

        // Check if the move is within board boundaries
        if (fromX < 0 || fromX >= 8 || fromY < 0 || fromY >= 8 || toX < 0 || toX >= 8 || toY < 0 || toY >= 8) {
            return false;
        }

        // More validation logic can be added here (e.g., checking if the move is legal according to chess rules)
        return true;
    }

    void makeMove(const std::string& move) {
        // Convert move to board coordinates and update the board
        int fromX = move[0] - 'a';
        int fromY = move[1] - '1';
        int toX = move[2] - 'a';
        int toY = move[3] - '1';

        Piece piece = board.getPiece(fromX, fromY);
        board.setPiece(toX, toY, piece);
        board.setPiece(fromX, fromY, Piece());
    }

    void clearScreen() const {
        #if defined(_WIN32) || defined(_WIN64)
            system("CLS");
        #else
            system("clear");
        #endif
    }
};

int main() {
    Game game;
    game.play();
    return 0;
}
