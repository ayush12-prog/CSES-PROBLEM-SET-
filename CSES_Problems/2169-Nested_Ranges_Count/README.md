# Nested Ranges Count (ID: 2169)

**Problem Link:** [https://cses.fi/problemset/task/2169/](https://cses.fi/problemset/task/2169/)

## Problem Description

Given n ranges, your task is to count for each range how many other ranges it contains and how many other ranges contain it.

## Solution

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Range {
    int l, r, id;
};

int bit[200005];
int n_val;

void update(int idx, int val) {
    for (; idx <= n_val; idx += idx & -idx) bit[idx] += val;
}

int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) sum += bit[idx];
    return sum;
}

bool compareRanges(const Range& a, const Range& b) {
    if (a.l != b.l) return a.l < b.l;
    return a.r > b.r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    n_val = n;

    vector<Range> ranges(n);
    vector<int> coords;
    for (int i = 0; i < n; i++) {
        cin >> ranges[i].l >> ranges[i].r;
        ranges[i].id = i;
        coords.push_back(ranges[i].r);
    }

    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    for (int i = 0; i < n; i++) {
        ranges[i].r = lower_bound(coords.begin(), coords.end(), ranges[i].r) - coords.begin() + 1;
    }

    sort(ranges.begin(), ranges.end(), compareRanges);

    vector<int> contains(n), contained(n);

    for (int i = n - 1; i >= 0; i--) {
        contains[ranges[i].id] = query(ranges[i].r);
        update(ranges[i].r, 1);
    }

    for (int i = 0; i <= n_val; i++) bit[i] = 0;

    for (int i = 0; i < n; i++) {
        contained[ranges[i].id] = (i - query(ranges[i].r - 1));
        update(ranges[i].r, 1);
    }

    for (int i = 0; i < n; i++) cout << contains[i] << (i == n - 1 ? "" : " ");
    cout << "\n";
    for (int i = 0; i < n; i++) cout << contained[i] << (i == n - 1 ? "" : " ");
    cout << "\n";

    return 0;
}
```
