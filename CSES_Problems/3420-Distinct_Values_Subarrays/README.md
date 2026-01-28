# Distinct Values Subarrays (ID: 3420)

**Problem Link:** [https://cses.fi/problemset/task/3420/](https://cses.fi/problemset/task/3420/)

## Problem Description

Given an array of n integers, count the number of subarrays where each element is distinct.

## Solution

```cpp
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<int> x(n);
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
        }

        map<int, int> last_pos;
        long long count = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            if (last_pos.count(x[right])) {
                left = max(left, last_pos[x[right]] + 1);
            }

            last_pos[x[right]] = right;
            count += (right - left + 1);
        }

        cout << count << endl;
    }
    return 0;
}
```
