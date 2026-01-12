// CSES Problem 1743: String Reorder
// Link: https://cses.fi/problemset/task/1743/
// Description: Your task is to reorder the characters of a string so that no two adjacent chara...

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    int n = s.length();
    vector<int> counts(26, 0);

    for (char c : s) {
        counts[c - 'A']++;
    }

    int max_freq = 0;
    for (int count : counts) {
        max_freq = max(max_freq, count);
    }

    if (max_freq > (n + 1) / 2) {
        cout << -1 << endl;
        return 0;
    }

    string result = "";
    char last_char = '\0';

    for (int i = 0; i < n; ++i) {
        int rem_len = n - i;

        int current_max_freq = 0;
        int max_char_index = -1;

        for (int c = 0; c < 26; ++c) {
            if (counts[c] > current_max_freq) {
                current_max_freq = counts[c];
                max_char_index = c;
            }
        }

        char char_to_pick = '\0';

        if (current_max_freq > rem_len / 2) {
            char_to_pick = (char)('A' + max_char_index);
        } else {
            for (int c = 0; c < 26; ++c) {
                if (counts[c] > 0 && (char)('A' + c) != last_char) {
                    char_to_pick = (char)('A' + c);
                    break;
                }
            }
        }

        if (char_to_pick == '\0' || char_to_pick == last_char) {
            cout << -1 << endl;
            return 0;
        }

        result += char_to_pick;
        counts[char_to_pick - 'A']--;
        last_char = char_to_pick;
    }

    cout << result << endl;

    return 0;
}
