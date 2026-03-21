// CSES Problem 1630: Tasks and Deadlines
// Link: https://cses.fi/problemset/task/1630/
// Description: You have to process n tasks. Each task has a duration and a deadline, and you wi...

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<long long, long long>> tasks(n);

    for (int i = 0; i < n; i++) {
        cin >> tasks[i].first >> tasks[i].second; // (duration, deadline)
    }

    // Sort by duration (Shortest Processing Time first)
    sort(tasks.begin(), tasks.end());

    long long current_time = 0;
    long long total_reward = 0;

    for (auto &task : tasks) {
        long long duration = task.first;
        long long deadline = task.second;

        current_time += duration;
        total_reward += (deadline - current_time);
    }

    cout << total_reward << "\n";

    return 0;
}
