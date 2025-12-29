// CSES Problem 1092: Two Sets
// Link: https://cses.fi/problemset/task/1092/
// Description: Your task is to divide the numbers 1,2,\ldots,n into two sets of equal sum....

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (cin >> n) {
        long long total = n * (n + 1) / 2;

        if (total % 2 != 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            vector<int> set_a;
            vector<int> set_b;

            int i = 1;
            if (n % 4 == 3) {
                set_a.push_back(1);
                set_a.push_back(2);
                set_b.push_back(3);
                i = 4;
            }

            while (i <= n) {
                set_a.push_back(i);
                set_a.push_back(i + 3);
                set_b.push_back(i + 1);
                set_b.push_back(i + 2);
                i += 4;
            }

            cout << set_a.size() << "\n";
            for (size_t k = 0; k < set_a.size(); ++k) {
                cout << set_a[k] << (k == set_a.size() - 1 ? "" : " ");
            }
            cout << "\n";

            cout << set_b.size() << "\n";
            for (size_t k = 0; k < set_b.size(); ++k) {
                cout << set_b[k] << (k == set_b.size() - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }
    return 0;
}
