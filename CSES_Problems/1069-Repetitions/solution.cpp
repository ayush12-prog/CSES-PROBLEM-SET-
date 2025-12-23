// CSES Problem 1069: Repetitions
// Link: https://cses.fi/problemset/task/1069/
// Description: You are given a DNA sequence: a string consisting of characters A, C, G, and T. ...

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int max_len = 0;
    int current_len = 0;
    char current_char = ' ';

    for (char c : s) {
        if (c == current_char) {
            current_len++;
        } else {
            max_len = max(max_len, current_len);
            current_char = c;
            current_len = 1;
        }
    }
    max_len = max(max_len, current_len);

    cout << max_len << endl;

    return 0;
}
