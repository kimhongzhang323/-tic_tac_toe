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

bool check_win(char board[3][3], char player){
    for (int i = 0; i<3; i++){
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player){
            return true;
        }

        if (board[0][i] == player && board[1][i] == player && board[2][i] == player){
            return true;
        }
    }
}

int main() {
    char board[3][3] = { { ' ', ' ', ' ' }, 
                         { ' ', ' ', ' ' }, 
                         { ' ', ' ', ' ' } };
    drawBoard(board);
    return 0;

    char player = 'X';
    int row, col;
    int turn;


    
}

