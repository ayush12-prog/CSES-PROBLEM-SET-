// CSES Problem 1084: Apartments
// Link: https://cses.fi/problemset/task/1084/
// Description: There are n applicants and m free apartments. Your task is to distribute the apa...

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    long long k;
    if (cin >> n >> m >> k) {
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        vector<long long> b(m);
        for (int i = 0; i < m; ++i) cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int matches = 0;
        int i = 0;
        int j = 0;

        while (i < n && j < m) {
            if (b[j] < a[i] - k) {
                j++;
            } else if (b[j] > a[i] + k) {
                i++;
            } else {
                matches++;
                i++;
                j++;
            }
        }

        cout << matches << endl;
    }
    return 0;
}
