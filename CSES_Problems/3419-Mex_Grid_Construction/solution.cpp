// CSES Problem 3419: Mex Grid Construction
// Link: https://cses.fi/problemset/task/3419/
// Description: Your task is to construct an n \times n grid where each square has the smallest ...

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int val = i ^ j;
                cout << val << (j == n - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }
    return 0;
}
