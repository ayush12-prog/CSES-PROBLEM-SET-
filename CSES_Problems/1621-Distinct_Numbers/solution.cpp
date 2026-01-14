// CSES Problem 1621: Distinct Numbers
// Link: https://cses.fi/problemset/task/1621/
// Description: You are given a list of n integers, and your task is to calculate the number of ...

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int ans = 0;
    if (n > 0) ans = 1;

    for (int i = 1; i < n; i++) {
        if (v[i] != v[i-1]) {
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}
