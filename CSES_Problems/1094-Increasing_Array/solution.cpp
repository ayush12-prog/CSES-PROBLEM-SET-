// CSES Problem 1094: Increasing Array
// Link: https://cses.fi/problemset/task/1094/
// Description: You are given an array of n integers. You want to modify the array so that it is...

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long x, current_max;
    cin >> current_max;

    long long moves = 0;

    for (int i = 1; i < n; i++) {
        cin >> x;
        if (x < current_max) {
            moves += current_max - x;
        } else {
            current_max = x;
        }
    }

    cout << moves << "\n";
    return 0;
}
