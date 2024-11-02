
#include <iostream>
#include <vector>

using namespace std;

// Function to initialize the board with empty spaces
void initializeBoard(vector<vector<char>> &board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the board
void printBoard(const vector<vector<char>> &board) {
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "  -+-+-" << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>> &board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

// Function to check if the board is full
bool checkDraw(const vector<vector<char>> &board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

// Main game function
void playGame() {
    vector<vector<char>> board(3, vector<char>(3));
    initializeBoard(board);

    char currentPlayer = 'X';
    bool gameOver = false;

    while (!gameOver) {
        printBoard(board);
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Validate the move
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        // Make the move
        board[row][col] = currentPlayer;

        // Check for a win or draw
        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameOver = true;
        } else if (checkDraw(board)) {
            printBoard(board);
            cout << "It's a draw!" << endl;
            gameOver = true;
        } else {
            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}

int main() {
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    playGame();
    return 0;
}
