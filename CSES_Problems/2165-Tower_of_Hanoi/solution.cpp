// CSES Problem 2165: Tower of Hanoi
// Link: https://cses.fi/problemset/task/2165/
// Description: The Tower of Hanoi game consists of three stacks (left, middle and right) and n ...

#include <iostream>
#include <vector>

using namespace std;

void hanoi(int n, int start, int end, int aux) {
    if (n == 0) return;
    hanoi(n - 1, start, aux, end);
    cout << start << " " << end << "\n";
    hanoi(n - 1, aux, end, start);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        cout << (1 << n) - 1 << "\n";
        hanoi(n, 1, 3, 2);
    }
    return 0;
}
