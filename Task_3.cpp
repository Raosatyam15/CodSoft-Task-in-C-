#include <iostream>
using namespace std;

char board[3][3]; // Tic-Tac-Toe board

// Function to initialize the board with numbers
void initializeBoard() {
    char num = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = num++;
        }
    }
}

// Function to display the current state of the board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

// Function to check if a player has won
bool checkWin(char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;

    return false;
}

// Function to check if the game is a draw
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false; // If any position is still a number, the game is not a draw
            }
        }
    }
    return true; // If all positions are filled, the game is a draw
}

// Function to update the board with the player's move
bool updateBoard(int move, char player) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = player;
        return true;
    } else {
        cout << "Invalid move! Try again.\n";
        return false;
    }
}

int main() {
    char currentPlayer = 'X';
    bool gameOver = false;
    int move;
    char playAgain = 'Y';

    while (playAgain == 'Y' || playAgain == 'y') {
        // Initialize the board and reset the game
        initializeBoard();
        gameOver = false;
        currentPlayer = 'X';

        cout << "Welcome to Tic-Tac-Toe!\n";

        // Game loop
        while (!gameOver) {
            displayBoard();
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            if (move >= 1 && move <= 9 && updateBoard(move, currentPlayer)) {
                if (checkWin(currentPlayer)) {
                    displayBoard();
                    cout << "Player " << currentPlayer << " wins!\n";
                    gameOver = true;
                } else if (checkDraw()) {
                    displayBoard();
                    cout << "The game is a draw!\n";
                    gameOver = true;
                } else {
                    // Switch players
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            }
        }

        // Ask if the players want to play again
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
    }

    cout << "Thanks for playing!\n";
    return 0;
}
