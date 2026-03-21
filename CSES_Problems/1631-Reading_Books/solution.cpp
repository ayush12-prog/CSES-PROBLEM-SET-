// CSES Problem 1631: Reading Books
// Link: https://cses.fi/problemset/task/1631/
// Description: There are n books, and Kotivalo and Justiina are going to read them all. For eac...

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long sum = 0;
    long long maxi = 0;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        sum += x;
        maxi = max(maxi, x);
    }

    cout << max(sum, 2 * maxi) << "\n";

    return 0;
}
