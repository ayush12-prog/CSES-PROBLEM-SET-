// CSES Problem 2205: Gray Code
// Link: https://cses.fi/problemset/task/2205/
// Description: A Gray code is a list of all 2^n bit strings of length n, where any two successi...

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        int limit = 1 << n;
        for (int i = 0; i < limit; ++i) {
            int val = i ^ (i >> 1);

            string s = "";
            for (int bit = n - 1; bit >= 0; --bit) {
                if ((val >> bit) & 1) {
                    s += '1';
                } else {
                    s += '0';
                }
            }
            cout << s << "\n";
        }
    }
    return 0;
}
