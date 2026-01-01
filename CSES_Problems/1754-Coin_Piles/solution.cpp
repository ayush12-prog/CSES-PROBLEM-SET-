// CSES Problem 1754: Coin Piles
// Link: https://cses.fi/problemset/task/1754/
// Description: You have two coin piles containing a and b coins. On each move, you can either r...

#include <iostream>

using namespace std;

void solve() {
    long long a, b;
    if (!(cin >> a >> b)) return;

    if ((a + b) % 3 == 0 && 2 * a >= b && 2 * b >= a) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
