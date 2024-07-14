#include <iostream>

using namespace std;

// Function prototypes
void displayBoard(char board[3][3]);
void playerMove(char board[3][3], char player);
bool checkWin(char board[3][3], char player);
bool checkTie(char board[3][3]);

int main() {
    char board[3][3] = { {'1', '2', '3'},
                         {'4', '5', '6'},
                         {'7', '8', '9'} };
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameTie = false;

    while (!gameWon && !gameTie) {
        displayBoard(board);
        playerMove(board, currentPlayer);
        gameWon = checkWin(board, currentPlayer);
        gameTie = checkTie(board);

        if (gameWon) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
        } else if (gameTie) {
            displayBoard(board);
            cout << "The game is a tie!" << endl;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}

void displayBoard(char board[3][3]) {
    cout << "Current board state:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void playerMove(char board[3][3], char player) {
    int move;
    bool validMove = false;

    while (!validMove) {
        cout << "Player " << player << ", enter your move (1-9): ";
        cin >> move;

        if (move >= 1 && move <= 9) {
            int row = (move - 1) / 3;
            int col = (move - 1) % 3;
            if (board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = player;
                validMove = true;
            } else {
                cout << "This spot is already taken. Try again." << endl;
            }
        } else {
            cout << "Invalid move. Enter a number between 1 and 9." << endl;
        }
    }
}

bool checkWin(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool checkTie(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}
