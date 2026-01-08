// CSES Problem 3399: Raab Game I
// Link: https://cses.fi/problemset/task/3399/
// Description: Consider a two player game where each player has n cards numbered 1,2,\dots,n. O...

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void run_test_case() {
    int n, a, b;
    if (!(cin >> n >> a >> b)) return;

    if (a + b > n) {
        cout << "NO" << "\n";
        return;
    }

    if (a + b > 0 && (a == 0 || b == 0)) {
        cout << "NO" << "\n";
        return;
    }

    cout << "YES" << "\n";

    vector<int> p1(n);
    vector<int> p2(n);

    iota(p1.begin(), p1.end(), 1);

    int ties = n - (a + b);
    int idx = 0;

    for (int k = 1; k <= ties; ++k) {
        p2[idx++] = k;
    }

    vector<int> decisive;
    for (int k = 0; k < a + b; ++k) {
        decisive.push_back(ties + 1 + k);
    }

    if (!decisive.empty()) {
        rotate(decisive.begin(), decisive.end() - b, decisive.end());

        for (int val : decisive) {
            p2[idx++] = val;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << p1[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    for (int i = 0; i < n; ++i) {
        cout << p2[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            run_test_case();
        }
    }
    return 0;
}
