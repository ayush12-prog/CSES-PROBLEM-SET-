// CSES Problem 1622: Creating Strings
// Link: https://cses.fi/problemset/task/1622/
// Description: Given a string, your task is to generate all different strings that can be creat...

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (cin >> s) {
        sort(s.begin(), s.end());
        vector<string> permutations;
        do {
            permutations.push_back(s);
        } while (next_permutation(s.begin(), s.end()));

        cout << permutations.size() << "\n";
        for (const string& p : permutations) {
            cout << p << "\n";
        }
    }
    return 0;
}
