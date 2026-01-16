# Ferris Wheel (ID: 1090)

**Problem Link:** [https://cses.fi/problemset/task/1090/](https://cses.fi/problemset/task/1090/)

## Problem Description

There are n children who want to go to a Ferris wheel, and your task is to find a gondola for each child.

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
    long long x;
    if (cin >> n >> x) {
        vector<long long> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }

        sort(p.begin(), p.end());

        int i = 0;
        int j = n - 1;
        int gondolas = 0;

        while (i <= j) {
            if (p[i] + p[j] <= x) {
                i++;
                j--;
            } else {
                j--;
            }
            gondolas++;
        }

        cout << gondolas << endl;
    }
    return 0;
}
```
