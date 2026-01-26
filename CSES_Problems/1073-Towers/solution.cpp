// CSES Problem 1073: Towers
// Link: https://cses.fi/problemset/task/1073/
// Description: You are given n cubes in a certain order, and your task is to build towers using...

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<int> towers;

        for (int i = 0; i < n; ++i) {
            int k;
            cin >> k;

            auto it = upper_bound(towers.begin(), towers.end(), k);

            if (it != towers.end()) {
                *it = k;
            } else {
                towers.push_back(k);
            }
        }

        cout << towers.size() << endl;
    }

    return 0;
}
