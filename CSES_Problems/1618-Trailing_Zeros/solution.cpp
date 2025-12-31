// CSES Problem 1618: Trailing Zeros
// Link: https://cses.fi/problemset/task/1618/
// Description: Your task is to calculate the number of trailing zeros in the factorial n!....

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    long long ans = 0;
    for (long long p = 5; p <= n; p *= 5) {
        ans += n / p;
    }

    cout << ans;
    return 0;
}
