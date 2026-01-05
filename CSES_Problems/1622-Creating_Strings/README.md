# Creating Strings (ID: 1622)

**Problem Link:** [https://cses.fi/problemset/task/1622/](https://cses.fi/problemset/task/1622/)

## Problem Description

Given a string, your task is to generate all different strings that can be created using its characters.

## Solution

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (cin >> s) {
        sort(s.begin(), s.end());
        vector<string> permutations;
        do {
            permutations.push_back(s);
        } while (next_permutation(s.begin(), s.end()));

        cout << permutations.size() << "\n";
        for (const string& p : permutations) {
            cout << p << "\n";
        }
    }
    return 0;
}
```
