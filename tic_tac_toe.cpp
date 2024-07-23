#include <iostream>
#include <vector>
#include <string>

using namespace std;

void drawBoard(char board[3][3]) 
{ 
    cout << "-------------\n"; 
    for (int i = 0; i < 3; i++) { 
        cout << "| "; 
        for (int j = 0; j < 3; j++) { 
            cout << board[i][j] << " | "; 
        } 
        cout << "\n-------------\n"; 
    } 
}

bool check_win(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

void player_turn(char board[3][3], char player) {
    int row, col;
    cout << "Player " << player << "'s turn\n";
    cout << "Enter row (0-2): ";
    cin >> row;
    cout << "Enter column (0-2): ";
    cin >> col;
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = player;
    } else {
        cout << "Invalid move. Try again\n";
        player_turn(board, player);
    }
}

void boardupdate(char board[3][3], int row, int col, char player) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = player;
    } else {
        cout << "Invalid move. Try again\n";
        player_turn(board, player);
    }
}

int main() {
    char board[3][3] = { { ' ', ' ', ' ' }, 
                         { ' ', ' ', ' ' }, 
                         { ' ', ' ', ' ' } };
    drawBoard(board);

    char player = 'X';
    int turn;

    for (turn = 0; turn < 9; turn++) {
        player_turn(board, player);
        drawBoard(board);
        if (check_win(board, player)) {
            cout << "Player " << player << " wins!\n";
            return 0;
        }
        // Alternate between players
        player = (player == 'X') ? 'O' : 'X';
    }

    cout << "It's a tie!\n";
    return 0;
}
