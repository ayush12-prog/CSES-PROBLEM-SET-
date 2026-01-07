// CSES Problem 1624: Chessboard and Queens
// Link: https://cses.fi/problemset/task/1624/
// Description: Your task is to place eight queens on a chessboard so that no two queens are att...

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> board(8);
bool col[8];
bool diag1[15];
bool diag2[15];
int solutions = 0;

void search(int y) {
    if (y == 8) {
        solutions++;
        return;
    }

    for (int x = 0; x < 8; x++) {
        if (board[y][x] == '*') continue;

        if (col[x] || diag1[x + y] || diag2[x - y + 7]) continue;

        col[x] = true;
        diag1[x + y] = true;
        diag2[x - y + 7] = true;

        search(y + 1);

        col[x] = false;
        diag1[x + y] = false;
        diag2[x - y + 7] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 8; ++i) {
        cin >> board[i];
    }

    search(0);

    cout << solutions << endl;

    return 0;
}
