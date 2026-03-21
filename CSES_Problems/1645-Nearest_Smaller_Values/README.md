# Nearest Smaller Values (ID: 1645)

**Problem Link:** [https://cses.fi/problemset/task/1645/](https://cses.fi/problemset/task/1645/)

## Problem Description

Given an array of n integers, your task is to find for each array position the nearest position to its left having a smaller value.

## Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    stack<int> st; // stores indices

    for (int i = 0; i < n; i++) {
        // Remove elements >= current
        while (!st.empty() && x[st.top()] >= x[i]) {
            st.pop();
        }

        // Output result
        if (st.empty()) cout << 0 << " ";
        else cout << st.top() + 1 << " "; // +1 for 1-based index

        // Push current index
        st.push(i);
    }

    cout << "\n";
    return 0;
}
```
