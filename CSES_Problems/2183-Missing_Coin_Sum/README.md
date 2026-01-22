# Missing Coin Sum (ID: 2183)

**Problem Link:** [https://cses.fi/problemset/task/2183/](https://cses.fi/problemset/task/2183/)

## Problem Description

You have n coins with positive integer values. What is the smallest sum you cannot create using a subset of the coins?

## Solution

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x.begin(), x.end());

    long long target = 1;
    for (int i = 0; i < n; i++) {
        if (x[i] > target) {
            break;
        }
        target += x[i];
    }

    cout << target << endl;

    return 0;
}
```
