# Reading Books (ID: 1631)

**Problem Link:** [https://cses.fi/problemset/task/1631/](https://cses.fi/problemset/task/1631/)

## Problem Description

There are n books, and Kotivalo and Justiina are going to read them all. For each book, you know the time it takes to read it.

## Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long sum = 0;
    long long maxi = 0;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        sum += x;
        maxi = max(maxi, x);
    }

    cout << max(sum, 2 * maxi) << "\n";

    return 0;
}
```
