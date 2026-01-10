// CSES Problem 3217: Knight Moves Grid
// Link: https://cses.fi/problemset/task/3217/
// Description: There is a knight on an n \times n chessboard. For each square, print the minimu...

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        dist[0][0] = 0;
        q.push({0, 0});

        int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;

            for (int i = 0; i < 8; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << dist[i][j] << (j == n - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }
    return 0;
}
