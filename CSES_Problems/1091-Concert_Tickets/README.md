# Concert Tickets (ID: 1091)

**Problem Link:** [https://cses.fi/problemset/task/1091/](https://cses.fi/problemset/task/1091/)

## Problem Description

There are n concert tickets available, each with a certain price. Then, m customers arrive, one after another.

## Solution

```cpp
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    multiset<int> tickets;
    for (int i = 0; i < n; ++i) {
        int h;
        cin >> h;
        tickets.insert(h);
    }

    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;

        // Find the first element strictly greater than t
        auto it = tickets.upper_bound(t);

        // If the iterator is at the beginning, all elements are > t
        if (it == tickets.begin()) {
            cout << -1 << "\n";
        } else {
            // Decrement to find the largest element <= t
            --it;
            cout << *it << "\n";
            // Remove the ticket from the pool
            tickets.erase(it);
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
```
