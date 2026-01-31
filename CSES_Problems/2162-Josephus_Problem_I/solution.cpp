// CSES Problem 2162: Josephus Problem I
// Link: https://cses.fi/problemset/task/2162/
// Description: Consider a game where there are n children (numbered 1,2,\dots,n) in a circle. D...

#include <iostream>
#include <vector>

using namespace std;

int bit[200005];
int n;

void update(int idx, int val) {
    for (; idx <= n; idx += idx & -idx)
    bit[idx] += val;
}

int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx)
    sum += bit[idx];
    return sum;
}

int find_kth(int k) {
    int idx = 0;
    for (int i = 1 << 18; i > 0; i >>= 1) {
        if (idx + i <= n && bit[idx + i] < k) {
            idx += i;
            k -= bit[idx];
        }
    }
    return idx + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n)) return 0;

    for (int i = 1; i <= n; i++) {
        update(i, 1);
    }

    int current_pos = 1;
    for (int i = n; i > 0; i--) {
        current_pos = (current_pos + 1) % i;
        if (current_pos == 0) current_pos = i;

        int child = find_kth(current_pos);
        cout << child << (i == 1 ? "" : " ");
        update(child, -1);
    }
    cout << endl;

    return 0;
}
