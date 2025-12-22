// CSES Problem 1068: Weird Algorithm
// Link: https://cses.fi/problemset/task/1068/
// Description: Consider an algorithm that takes as input a positive integer n. If n is even, th...

#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    while (true) {
        cout << n;
        if (n == 1) break;
        cout << " ";
        if (n % 2 == 0)
        n /= 2;
        else
        n = 3 * n + 1;
    }
    return 0;
}
