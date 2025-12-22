// CSES Problem 1083: Missing Number
// Link: https://cses.fi/problemset/task/1083/
// Description: You are given all numbers between 1,2,\ldots,n except one. Your task is to find ...

#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;
    long long sum = n * (n + 1) / 2;
    long long input;
    for (int i = 0; i < n - 1; ++i) {
        cin >> input;
        sum -= input;
    }
    cout << sum << endl;
    return 0;
}
