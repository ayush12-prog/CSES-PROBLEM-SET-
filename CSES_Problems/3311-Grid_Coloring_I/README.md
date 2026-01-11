# Grid Coloring I (ID: 3311)

**Problem Link:** [https://cses.fi/problemset/task/3311/](https://cses.fi/problemset/task/3311/)

## Problem Description

You are given an n\times m grid where each cell contains one character A, B, C or D.

## Solution

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int rows, cols;
    if (cin >> rows >> cols) {
        vector<string> board(rows);
        for (int i = 0; i < rows; ++i) {
            cin >> board[i];
        }

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if ((r + c) % 2 == 0) {
                    if (board[r][c] == 'A') {
                        board[r][c] = 'B';
                    } else {
                        board[r][c] = 'A';
                    }
                } else {
                    if (board[r][c] == 'C') {
                        board[r][c] = 'D';
                    } else {
                        board[r][c] = 'C';
                    }
                }
            }
        }

        for (int i = 0; i < rows; ++i) {
            cout << board[i] << "\n";
        }
    }
    return 0;
}
```
