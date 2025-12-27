# Number Spiral (ID: 1071)

**Problem Link:** [https://cses.fi/problemset/task/1071/](https://cses.fi/problemset/task/1071/)

## Problem Description

A number spiral is an infinite grid whose upper-left square has number 1. Here are the first five layers of the spiral:

## Solution

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            long long y, x;
            cin >> y >> x;
            long long z = max(y, x);
            long long ans;
            if (z % 2 == 0) {
                if (y == z) {
                    ans = z * z - x + 1;
                } else {
                    ans = (z - 1) * (z - 1) + y;
                }
            } else {
                if (y == z) {
                    ans = (z - 1) * (z - 1) + x;
                } else {
                    ans = z * z - y + 1;
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
```
