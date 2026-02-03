# Nested Ranges Check (ID: 2168)

**Problem Link:** [https://cses.fi/problemset/task/2168/](https://cses.fi/problemset/task/2168/)

## Problem Description

Given n ranges, your task is to determine for each range if it contains some other range and if some other range contains it.

## Solution

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Range {
    int l, r, id;
};

bool compareRanges(const Range& a, const Range& b) {
    if (a.l != b.l) return a.l < b.l;
    return a.r > b.r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Range> ranges(n);
    for (int i = 0; i < n; i++) {
        cin >> ranges[i].l >> ranges[i].r;
        ranges[i].id = i;
    }

    sort(ranges.begin(), ranges.end(), compareRanges);

    vector<int> contains(n, 0);
    vector<int> contained(n, 0);

    int min_r = 2e9;
    for (int i = n - 1; i >= 0; i--) {
        if (ranges[i].r >= min_r) {
            contains[ranges[i].id] = 1;
        }
        min_r = min(min_r, ranges[i].r);
    }

    int max_r = 0;
    for (int i = 0; i < n; i++) {
        if (ranges[i].r <= max_r) {
            contained[ranges[i].id] = 1;
        }
        max_r = max(max_r, ranges[i].r);
    }

    for (int i = 0; i < n; i++) cout << contains[i] << (i == n - 1 ? "" : " ");
    cout << "\n";
    for (int i = 0; i < n; i++) cout << contained[i] << (i == n - 1 ? "" : " ");
    cout << "\n";

    return 0;
}
```
