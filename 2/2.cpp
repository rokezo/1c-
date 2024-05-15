#include <iostream>

using namespace std;

const int SIZE = 4;

void printBoard(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void shuffleBoard(int board[SIZE][SIZE]) {
    int seed = 1;
    for (int i = 0; i < SIZE * SIZE; i++) {
        int x = (seed * 1103515245 + 12345) % SIZE;
        int y = (seed * 1103515245 + 12345) % SIZE;
        seed = (seed * 1103515245 + 12345) % 2147483647;
        int temp = board[x][y];
        board[x][y] = board[(x + 1) % SIZE][(y + 1) % SIZE];
        board[(x + 1) % SIZE][(y + 1) % SIZE] = temp;
    }
}

bool isSolved(int board[SIZE][SIZE]) {
    int count = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != count) {
                return false;
            }
            count++;
        }
    }
    return true;
}

int main() {
    int board[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = i * SIZE + j + 1;
        }
    }
    board[SIZE - 1][SIZE - 1] = 0; 

    shuffleBoard(board);

    while (true) {
        printBoard(board);
        int move;
        cout << "Enter the number to move (0 to quit): ";
        cin >> move;
        if (move == 0) {
            break;
        }
        bool validMove = false;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == move) {
                    if (i > 0 && board[i - 1][j] == 0) {
                        swap(board[i][j], board[i - 1][j]);
                        validMove = true;
                    }
                    else if (i < SIZE - 1 && board[i + 1][j] == 0) {
                        swap(board[i][j], board[i + 1][j]);
                        validMove = true;
                    }
                    else if (j > 0 && board[i][j - 1] == 0) {
                        swap(board[i][j], board[i][j - 1]);
                        validMove = true;
                    }
                    else if (j < SIZE - 1 && board[i][j + 1] == 0) {
                        swap(board[i][j], board[i][j + 1]);
                        validMove = true;
                    }
                }
            }
        }
        if (!validMove) {
            cout << "Invalid move. Try again." << endl;
        }
        if (isSolved(board)) {
            cout << "Congratulations! You solved the puzzle." << endl;
            break;
        }
    }

    return 0;
}