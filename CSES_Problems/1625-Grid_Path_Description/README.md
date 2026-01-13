# Grid Path Description (ID: 1625)

**Problem Link:** [https://cses.fi/problemset/task/1625/](https://cses.fi/problemset/task/1625/)

## Problem Description

There are 88418 paths in a 7 \times 7 grid from the upper-left square to the lower-left square. Each path corresponds to a 48-character description consisting of characters D (down), U (up), L (left) and R (right).

## Solution

```cpp
#include <iostream>
#include <string>

using namespace std;

bool visited[9][9];
int paths_count = 0;
string path_desc;

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

void dfs(int r, int c, int step) {
    if (r == 7 && c == 1) {
        if (step == 48) {
            paths_count++;
        }
        return;
    }

    if (visited[r-1][c] && visited[r+1][c] && !visited[r][c-1] && !visited[r][c+1]) return;
    if (visited[r][c-1] && visited[r][c+1] && !visited[r-1][c] && !visited[r+1][c]) return;

    visited[r][c] = true;

    if (path_desc[step] != '?') {
        int dir = -1;
        char move = path_desc[step];

        if (move == 'U') dir = 0;
        else if (move == 'R') dir = 1;
        else if (move == 'D') dir = 2;
        else if (move == 'L') dir = 3;

        int nr = r + dr[dir];
        int nc = c + dc[dir];

        if (!visited[nr][nc]) {
            dfs(nr, nc, step + 1);
        }
    } else {
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (!visited[nr][nc]) {
                dfs(nr, nc, step + 1);
            }
        }
    }

    visited[r][c] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (cin >> path_desc) {
        for (int i = 0; i < 9; ++i) {
            visited[0][i] = true;
            visited[8][i] = true;
            visited[i][0] = true;
            visited[i][8] = true;
        }

        dfs(1, 1, 0);

        cout << paths_count << endl;
    }
    return 0;
}
```
