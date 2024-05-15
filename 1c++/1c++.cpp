#include <iostream>

using namespace std;

const int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
const int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

bool isValidMove(int x, int y, int n, bool visited[8][8]) {
    return (x >= 0 && x < n && y >= 0 && y < n && !visited[x][y]);
}

bool knightTour(int x, int y, int n, int move, bool visited[8][8], int path[64], int next) {
    if (move == n * n) {
        for (int i = 0; i < n * n; i++) {
            cout << "(" << path[i] / n << ", " << path[i] % n << ") ";
        }
        cout << endl;
        return true;
    }

    visited[x][y] = true;
    path[move] = x * n + y;

    bool result = false;

    for (int i = 0; i < 8; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isValidMove(newX, newY, n, visited)) {
            result = knightTour(newX, newY, n, move + 1, visited, path, i);
            if (result) {
                break;
            }
        }
    }

    visited[x][y] = false;

    return result;
}

int main() {
    int n;
    cout << "Enter the size of the board (6 or 8): ";
    cin >> n;

    if (n != 6 && n != 8) {
        cout << "Invalid board size. Exiting..." << endl;
        return 1;
    }

    bool visited[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            visited[i][j] = false;
        }
    }

    int path[64];
    for (int i = 0; i < 64; i++) {
        path[i] = -1;
    }

    int x, y;
    cout << "Enter starting position (x, y): ";
    cin >> x >> y;

    knightTour(x, y, n, 0, visited, path, 0);

    return 0;
}