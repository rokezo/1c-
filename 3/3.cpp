#include <iostream>

using namespace std;

const short int size = 3;
char Table[size][size];

void Show_Matrix(char Table[][size]) {
    system("clear"); // Use "clear" instead of "cls" for Unix-based systems
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << Table[i][j] << ' ';
            if (j < size - 1) cout << '|';
        }
        cout << endl;
        if (i < size - 1) cout << "--|--|--" << endl;
    }
}

void Logo() {
    cout << " 1 | 2 | 3" << endl;
    cout << "--|--|--" << endl;
    cout << " 4 | 5 | 6" << endl;
    cout << "--|--|--" << endl;
    cout << " 7 | 8 | 9" << endl;
}

bool IsValidMove(char Table[][size], int move) {
    return Table[(move - 1) / size][(move - 1) % size] == ' ';
}

void MakeMove(char Table[][size], int move, char symbol) {
    Table[(move - 1) / size][(move - 1) % size] = symbol;
}

bool CheckWin(char Table[][size], char symbol) {
    // Check rows and columns
    for (int i = 0; i < size; ++i) {
        if (Table[i][0] == symbol && Table[i][1] == symbol && Table[i][2] == symbol) return true;
        if (Table[0][i] == symbol && Table[1][i] == symbol && Table[2][i] == symbol) return true;
    }
    // Check diagonals
    if (Table[0][0] == symbol && Table[1][1] == symbol && Table[2][2] == symbol) return true;
    if (Table[0][2] == symbol && Table[1][1] == symbol && Table[2][0] == symbol) return true;
    return false;
}

int main() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            Table[i][j] = ' ';
        }
    }

    int count = 0, move;
    char symbol = 'X';
    do {
        if (count % 2) {
            // Simple AI implementation, just random move
            move = rand() % 9 + 1;
            while (!IsValidMove(Table, move)) {
                move = rand() % 9 + 1;
            }
            cout << "\nComputer's move: " << move << endl;
        }
        else {
            Logo();
            Show_Matrix(Table);
            cout << "\nPlayer's move (X): ";
            cin >> move;
            while (!IsValidMove(Table, move)) {
                cout << "Invalid move, try again: ";
                cin >> move;
            }
        }
        MakeMove(Table, move, symbol);
        if (CheckWin(Table, symbol)) {
            Show_Matrix(Table);
            cout << "\nPlayer " << (symbol == 'X' ? 'O' : 'X') << " wins!" << endl;
            break;
        }
        symbol = symbol == 'X' ? 'O' : 'X';
        count++;
    } while (count < 9);
    if (count == 9) {
        Show_Matrix(Table);
        cout << "\nDraw!" << endl;
    }
    return 0;
}