// CSES Problem 1623: Apple Division
// Link: https://cses.fi/problemset/task/1623/
// Description: There are n apples with known weights. Your task is to divide the apples into tw...

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long min_diff;
long long total_sum;

void solve(int idx, long long current_sum, int n, const vector<long long>& weights) {
    if (idx == n) {
        long long diff = abs((total_sum - current_sum) - current_sum);
        min_diff = min(min_diff, diff);
        return;
    }

    solve(idx + 1, current_sum + weights[idx], n, weights);

    solve(idx + 1, current_sum, n, weights);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<long long> weights(n);
        total_sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> weights[i];
            total_sum += weights[i];
        }

        min_diff = total_sum;

        solve(0, 0, n, weights);

        cout << min_diff << "\n";
    }
    return 0;
}
