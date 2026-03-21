# Sum of Three Values (ID: 1641)

**Problem Link:** [https://cses.fi/problemset/task/1641/](https://cses.fi/problemset/task/1641/)

## Problem Description

You are given an array of n integers, and your task is to find three values (at distinct positions) whose sum is x.

## Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;

    vector<pair<long long, int>> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1; // store original index (1-based)
    }

    // Sort by value
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        long long target = x - a[i].first;

        int l = i + 1;
        int r = n - 1;

        while (l < r) {
            long long sum = a[l].first + a[r].first;

            if (sum == target) {
                cout << a[i].second << " "
                << a[l].second << " "
                << a[r].second << "\n";
                return 0;
            }
            else if (sum < target) {
                l++;
            }
            else {
                r--;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
```
