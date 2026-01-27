# Traffic Lights (ID: 1163)

**Problem Link:** [https://cses.fi/problemset/task/1163/](https://cses.fi/problemset/task/1163/)

## Problem Description

There is a street of length x whose positions are numbered 0,1,\ldots,x. Initially there are no traffic lights, but n sets of traffic lights are added to the street one after another.

## Solution

```cpp
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, n;
    if (cin >> x >> n) {
        set<int> positions;
        multiset<int> lengths;

        positions.insert(0);
        positions.insert(x);
        lengths.insert(x);

        for (int i = 0; i < n; ++i) {
            int p;
            cin >> p;

            auto it = positions.upper_bound(p);
            int right = *it;
            it--;
            int left = *it;

            int old_len = right - left;
            auto len_it = lengths.find(old_len);
            if (len_it != lengths.end()) {
                lengths.erase(len_it);
            }

            lengths.insert(p - left);
            lengths.insert(right - p);
            positions.insert(p);

            cout << *lengths.rbegin() << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}
```
