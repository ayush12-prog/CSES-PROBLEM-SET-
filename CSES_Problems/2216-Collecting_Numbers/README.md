# Collecting Numbers (ID: 2216)

**Problem Link:** [https://cses.fi/problemset/task/2216/](https://cses.fi/problemset/task/2216/)

## Problem Description

You are given an array that contains each number between 1 \dots n exactly once. Your task is to collect the numbers from 1 to n in increasing order.

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
        vector<int> pos(n + 1);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            pos[x] = i;
        }

        int rounds = 1;
        for (int i = 1; i < n; ++i) {
            if (pos[i + 1] < pos[i]) {
                rounds++;
            }
        }

        cout << rounds << endl;
    }
    return 0;
}
```
