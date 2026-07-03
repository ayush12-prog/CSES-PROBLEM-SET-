// CSES Problem 1660: Subarray Sums I
// Link: https://cses.fi/problemset/task/1660/
// Description: Given an array of n positive integers, your task is to count the number of subar...

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x;
    if (!(cin >> n >> x)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long current_sum = 0;
    int left = 0;
    long long count = 0;

    for (int right = 0; right < n; ++right) {
        current_sum += a[right];

        while (current_sum > x && left <= right) {
            current_sum -= a[left];
            left++;
        }

        if (current_sum == x) {
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}
