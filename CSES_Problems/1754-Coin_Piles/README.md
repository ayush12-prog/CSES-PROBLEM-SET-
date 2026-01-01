# Coin Piles (ID: 1754)

**Problem Link:** [https://cses.fi/problemset/task/1754/](https://cses.fi/problemset/task/1754/)

## Problem Description

You have two coin piles containing a and b coins. On each move, you can either remove one coin from the left pile and two coins from the right pile, or two coins from the left pile and one coin from the right pile.

## Solution

```cpp
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
```
