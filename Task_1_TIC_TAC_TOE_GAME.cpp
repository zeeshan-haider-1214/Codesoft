#include <iostream>
#include <string>
#include <vector>


using namespace std;

void displayBoard(const vector<vector<char>>& board, const string& player1, const string& player2) {
    cout << "******TIC-TAC-TOE GAME******" << endl;
    cout << "Board places: 1 2 3 4 5 6 7 8 9" << endl;
    cout << player1 << " (X) vs " << player2 << " (O)" << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X' || board[i][j] == 'O') {
                cout << board[i][j];
            } else {
                int spaceNumber = i * 3 + j + 1;
                cout << spaceNumber;
            }
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    char currentPlayer = 'X';
    vector<vector<char>> board(3, vector<char>(3, ' '));
    string player1, player2;

    cout << "Enter Player 1 First name: ";
    cin >> player1;
    cout << "Enter Player 2 First name: ";
    cin >> player2;

    bool playAgain = true;

    while (playAgain) {
        bool gameOn = true;

        while (gameOn) {
            displayBoard(board, player1, player2);
            cout << (currentPlayer == 'X' ? player1 : player2) << " (" << currentPlayer << "), enter your place where you want to paste your move (1-9): ";
            int move;
            cin >> move;

            if (move < 1 || move > 9) {
                cout << "Invalid move. Please enter a number between 1 and 9." << endl;
                continue;
            }

            int row = (move - 1) / 3;
            int col = (move - 1) % 3;

            if (board[row][col] == ' ') {
                board[row][col] = currentPlayer;

                if (checkWin(board, currentPlayer)) {
                    displayBoard(board, player1, player2);
                    cout << "Congratulations! " << (currentPlayer == 'X' ? player1 : player2) << " win the match" << endl;
                    gameOn = false;
                } else if (checkDraw(board)) {
                    displayBoard(board, player1, player2);
                    cout << "It's a draw!" << endl;
                    gameOn = false;
                } else {
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            } else {
                cout << "Invalid move. Space is already filled. Try again." << endl;
            }
        }

        cout << "Do you want to play again? Please give your answer in (yes OR no): ";
        string playAgainResponse;
        cin >> playAgainResponse;

        if (playAgainResponse != "yes" && playAgainResponse != "Yes") {
            playAgain = false;
        } else {
            // Reset the game board for a new game
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    board[i][j] = ' ';
                }
            }
        }
    }

    cout << "Thanks for playing!" << endl;
    cout<<"This is the first Task1"<<endl;

    return 0;
}
