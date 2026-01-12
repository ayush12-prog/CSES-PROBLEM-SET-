# Digit Queries (ID: 2431)

**Problem Link:** [https://cses.fi/problemset/task/2431/](https://cses.fi/problemset/task/2431/)

## Problem Description

Consider an infinite string that consists of all positive integers in increasing order:

## Solution

```cpp
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    long long k;
    cin >> k;

    long long len = 1;
    long long count = 9;
    long long start = 1;

    while (k > len * count) {
        k -= len * count;
        len++;
        count *= 10;
        start *= 10;
    }

    start += (k - 1) / len;
    string s = to_string(start);
    cout << s[(k - 1) % len] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    if (cin >> q) {
        while (q--) {
            solve();
        }
    }
    return 0;
}
```
