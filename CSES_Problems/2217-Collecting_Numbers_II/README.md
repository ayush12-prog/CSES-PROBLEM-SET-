# Collecting Numbers II (ID: 2217)

**Problem Link:** [https://cses.fi/problemset/task/2217/](https://cses.fi/problemset/task/2217/)

## Problem Description

You are given an array that contains each number between 1 \dots n exactly once. Your task is to collect the numbers from 1 to n in increasing order.

## Solution

```cpp
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (cin >> n >> m) {
        vector<int> x(n + 1);
        vector<int> pos(n + 1);

        for (int i = 1; i <= n; ++i) {
            cin >> x[i];
            pos[x[i]] = i;
        }

        int rounds = 1;
        for (int i = 1; i < n; ++i) {
            if (pos[i + 1] < pos[i]) {
                rounds++;
            }
        }

        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;

            int u = x[a];
            int v = x[b];

            set<int> check_vals;
            if (u > 1) check_vals.insert(u - 1);
            if (u < n) check_vals.insert(u);
            if (v > 1) check_vals.insert(v - 1);
            if (v < n) check_vals.insert(v);

            for (int val : check_vals) {
                if (pos[val + 1] < pos[val]) {
                    rounds--;
                }
            }

            swap(x[a], x[b]);
            pos[u] = b;
            pos[v] = a;

            for (int val : check_vals) {
                if (pos[val + 1] < pos[val]) {
                    rounds++;
                }
            }

            cout << rounds << "\n";
        }
    }
    return 0;
}
```
