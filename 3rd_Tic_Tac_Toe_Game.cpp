#include <iostream>
using namespace std;

char board[3][3];   // 3x3 grid
string playerX = "Shubham";
string playerO = "Yogesh";
char currentPlayer; // 'X' or 'O'

void resetBoard() {
    char cell = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = cell++;
        }
    }
    currentPlayer = 'X';
}

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) return true;
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool makeMove(int cell) {
    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "⚠️ Cell already taken! Try again.\n";
        return false;
    }
    board[row][col] = currentPlayer;
    return true;
}

string getPlayerName() {
    return (currentPlayer == 'X') ? playerX : playerO;
}

int main() {
    char playAgain;
    do {
        resetBoard();
        bool gameOver = false;

        cout << "🎮 Welcome to Tic-Tac-Toe!\n";
        displayBoard();

        while (!gameOver) {
            int move;
            cout << getPlayerName() << " (" << currentPlayer << "), enter your move (1-9): ";
            cin >> move;

            if (move < 1 || move > 9) {
                cout << "⚠️ Invalid move! Please choose between 1-9.\n";
                continue;
            }

            if (!makeMove(move)) continue;

            displayBoard();

            if (checkWin()) {
                cout << "🏆 " << getPlayerName() << " wins!\n";
                gameOver = true;
            } else if (checkDraw()) {
                cout << "🤝 It's a draw!\n";
                gameOver = true;
            } else {
                switchPlayer();
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! 👋\n";
    return 0;
}