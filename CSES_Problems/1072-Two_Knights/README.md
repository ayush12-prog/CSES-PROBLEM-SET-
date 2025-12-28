# Two Knights (ID: 1072)

**Problem Link:** [https://cses.fi/problemset/task/1072/](https://cses.fi/problemset/task/1072/)

## Problem Description

Your task is to count for k=1,2,\ldots,n the number of ways two knights can be placed on a k \times k chessboard so that they do not attack each other.

## Solution

```cpp
#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;
    for (long long k = 1; k <= n; k++) {
        long long total = (k * k) * (k * k - 1) / 2;
        long long attack = 4 * (k - 1) * (k - 2);
        cout << total - attack << "\n";
    }
    return 0;
}
```
