// CSES Problem 1640: Sum of Two Values
// Link: https://cses.fi/problemset/task/1640/
// Description: You are given an array of n integers, and your task is to find two values (at di...

#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x;
    if (cin >> n >> x) {
        map<long long, int> values;

        for (int i = 1; i <= n; ++i) {
            long long val;
            cin >> val;

            long long needed = x - val;

            if (values.count(needed)) {
                cout << values[needed] << " " << i << endl;
                return 0;
            }

            values[val] = i;
        }

        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
