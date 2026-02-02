// CSES Problem 2163: Josephus Problem II
// Link: https://cses.fi/problemset/task/2163/
// Description: Consider a game where there are n children (numbered 1,2,\dots,n) in a circle. D...

#include <iostream>
#include <vector>

using namespace std;

int bit[200005];
int n_limit;

void update(int i, int val) {
    for (; i <= n_limit; i += i & -i)
    bit[i] += val;
}

int find_kth(int k) {
    int idx = 0;
    for (int i = 1 << 18; i > 0; i >>= 1) {
        if (idx + i <= n_limit && bit[idx + i] < k) {
            idx += i;
            k -= bit[idx];
        }
    }
    return idx + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;
    n_limit = n;

    for (int i = 1; i <= n; i++) update(i, 1);

    int pos = 0;
    for (int sz = n; sz > 0; sz--) {
        pos = (pos + k) % sz;
        int res = find_kth(pos + 1);
        cout << res << (sz == 1 ? "" : " ");
        update(res, -1);
    }
    cout << endl;

    return 0;
}
