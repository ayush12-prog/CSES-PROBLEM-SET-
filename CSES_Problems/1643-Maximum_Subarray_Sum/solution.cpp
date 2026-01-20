// CSES Problem 1643: Maximum Subarray Sum
// Link: https://cses.fi/problemset/task/1643/
// Description: Given an array of n integers, your task is to find the maximum sum of values in ...

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<long long> x(n);
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
        }

        long long max_so_far = x[0];
        long long current_sum = x[0];

        for (int i = 1; i < n; ++i) {
            current_sum = max(x[i], current_sum + x[i]);
            max_so_far = max(max_so_far, current_sum);
        }

        cout << max_so_far << endl;
    }
    return 0;
}
