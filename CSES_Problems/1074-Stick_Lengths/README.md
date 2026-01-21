# Stick Lengths (ID: 1074)

**Problem Link:** [https://cses.fi/problemset/task/1074/](https://cses.fi/problemset/task/1074/)

## Problem Description

There are n sticks with some lengths. Your task is to modify the sticks so that each stick has the same length.

## Solution

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<long long> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }

        // Sort to find the median
        sort(p.begin(), p.end());

        // The median minimizes the sum of absolute differences
        long long median = p[n / 2];
        long long cost = 0;

        for (long long val : p) {
            cost += abs(val - median);
        }

        cout << cost << endl;
    }
    return 0;
}
```
