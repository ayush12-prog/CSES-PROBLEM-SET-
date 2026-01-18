// CSES Problem 1619: Restaurant Customers
// Link: https://cses.fi/problemset/task/1619/
// Description: You are given the arrival and leaving times of n customers in a restaurant....

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<pair<int, int>> events;
        // Reserve space to avoid reallocations
        events.reserve(2 * n);

        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            // Type 1 for arrival, -1 for leaving
            events.push_back({a, 1});
            events.push_back({b, -1});
        }

        sort(events.begin(), events.end());

        int current_customers = 0;
        int max_customers = 0;

        for (const auto& event : events) {
            current_customers += event.second;
            max_customers = max(max_customers, current_customers);
        }

        cout << max_customers << endl;
    }
    return 0;
}
