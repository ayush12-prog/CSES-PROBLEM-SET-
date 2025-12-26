# Permutations (ID: 1070)

**Problem Link:** [https://cses.fi/problemset/task/1070/](https://cses.fi/problemset/task/1070/)

## Problem Description

A permutation of integers 1,2,\ldots,n is called beautiful if there are no adjacent elements whose difference is 1.

## Solution

```cpp
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n == 1) {
        cout << "1";
    } else if (n <= 3) {
        cout << "NO SOLUTION";
    } else {
        // First loop: starts at n-1, decreases by 2
        for (int i = n - 1; i > 0; i -= 2) {
            cout << i << " ";
        }
        // Second loop: starts at n, decreases by 2
        for (int i = n; i > 0; i -= 2) {
            cout << i << " ";
        }
    }

    return 0;
}
```
