// CSES Problem 1642: Sum of Four Values
// Link: https://cses.fi/problemset/task/1642/
// Description: You are given an array of n integers, and your task is to find four values (at d...

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // map: pair sum -> pair of indices
    unordered_map<long long, pair<int, int>> mp;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            long long current_sum = a[i] + a[j];
            long long needed = x - current_sum;

            // Check if complement pair exists
            if (mp.find(needed) != mp.end()) {
                auto [p, q] = mp[needed];

                // Ensure all indices are distinct
                if (p != i && p != j && q != i && q != j) {
                    cout << p + 1 << " " << q + 1 << " "
                    << i + 1 << " " << j + 1 << "\n";
                    return 0;
                }
            }
        }

        // Store pairs AFTER checking to avoid reuse of same indices
        for (int j = 0; j < i; j++) {
            mp[a[i] + a[j]] = {j, i};
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
