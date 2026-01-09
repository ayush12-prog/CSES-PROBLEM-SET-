# Mex Grid Construction (ID: 3419)

**Problem Link:** [https://cses.fi/problemset/task/3419/](https://cses.fi/problemset/task/3419/)

## Problem Description

Your task is to construct an n \times n grid where each square has the smallest nonnegative integer that does not appear to the left on the same row or above on the same column.

## Solution

```cpp
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
```
