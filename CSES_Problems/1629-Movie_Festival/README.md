# Movie Festival (ID: 1629)

**Problem Link:** [https://cses.fi/problemset/task/1629/](https://cses.fi/problemset/task/1629/)

## Problem Description

In a movie festival n movies will be shown. You know the starting and ending time of each movie. What is the maximum number of movies you can watch entirely?

## Solution

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Movie {
    int start, end;
};

bool compareMovies(const Movie& a, const Movie& b) {
    return a.end < b.end;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<Movie> movies(n);
        for (int i = 0; i < n; ++i) {
            cin >> movies[i].start >> movies[i].end;
        }

        sort(movies.begin(), movies.end(), compareMovies);

        int count = 0;
        int current_end_time = 0;

        for (const auto& m : movies) {
            if (m.start >= current_end_time) {
                count++;
                current_end_time = m.end;
            }
        }

        cout << count << endl;
    }
    return 0;
}
```
