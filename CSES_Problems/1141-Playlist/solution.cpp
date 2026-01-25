// CSES Problem 1141: Playlist
// Link: https://cses.fi/problemset/task/1141/
// Description: You are given a playlist of a radio station since its establishment. The playlis...

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<int> k(n);
        for (int i = 0; i < n; ++i) {
            cin >> k[i];
        }

        map<int, int> last_seen;
        int max_len = 0;
        int start = 0;

        for (int end = 0; end < n; ++end) {
            int current_song = k[end];

            if (last_seen.count(current_song) && last_seen[current_song] >= start) {
                start = last_seen[current_song] + 1;
            }

            last_seen[current_song] = end;
            max_len = max(max_len, end - start + 1);
        }

        cout << max_len << endl;
    }
    return 0;
}
