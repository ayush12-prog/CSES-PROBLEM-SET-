# Factory Machines (ID: 1620)

**Problem Link:** [https://cses.fi/problemset/task/1620/](https://cses.fi/problemset/task/1620/)

## Problem Description

A factory has n machines which can be used to make products. Your goal is to make a total of t products.

## Solution

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long unit_count, required_items;
    if (cin >> unit_count >> required_items) {
        vector<long long> duration_array(unit_count);
        long long minimum_delay = 2e9;

        for (int i = 0; i < unit_count; ++i) {
            cin >> duration_array[i];
            if (duration_array[i] < minimum_delay) {
                minimum_delay = duration_array[i];
            }
        }

        long long lower_limit = 1;
        long long upper_limit = minimum_delay * required_items;
        long long best_timeline = upper_limit;

        while (lower_limit <= upper_limit) {
            long long midpoint = lower_limit + (upper_limit - lower_limit) / 2;
            long long items_built = 0;

            for (int i = 0; i < unit_count; ++i) {
                items_built += midpoint / duration_array[i];
                if (items_built >= required_items) {
                    break;
                }
            }

            if (items_built >= required_items) {
                best_timeline = midpoint;
                upper_limit = midpoint - 1;
            } else {
                lower_limit = midpoint + 1;
            }
        }

        cout << best_timeline << "\n";
    }

    return 0;
}
```
