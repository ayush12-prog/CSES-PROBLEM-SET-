# Bit Strings (ID: 1617)

**Problem Link:** [https://cses.fi/problemset/task/1617/](https://cses.fi/problemset/task/1617/)

## Problem Description

Your task is to calculate the number of bit strings of length n.

## Solution

```cpp
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        long long result = 1;
        long long base = 2;
        long long mod = 1e9 + 7;

        while (n > 0) {
            if (n % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            n /= 2;
        }

        cout << result << "\n";
    }
    return 0;
}
```
