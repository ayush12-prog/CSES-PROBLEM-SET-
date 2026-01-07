# Chessboard and Queens (ID: 1624)

**Problem Link:** [https://cses.fi/problemset/task/1624/](https://cses.fi/problemset/task/1624/)

## Problem Description

Your task is to place eight queens on a chessboard so that no two queens are attacking each other. As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares. However, the reserved squares do not prevent queens from attacking each other.

## Solution

```cpp
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
```
