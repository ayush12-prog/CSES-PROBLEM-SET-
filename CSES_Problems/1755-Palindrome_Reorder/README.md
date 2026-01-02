# Palindrome Reorder (ID: 1755)

**Problem Link:** [https://cses.fi/problemset/task/1755/](https://cses.fi/problemset/task/1755/)

## Problem Description

Given a string, your task is to reorder its letters in such a way that it becomes a palindrome (i.e., it reads the same forwards and backwards).

## Solution

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> a(26);
    for(char c : s) a[c - 'A']++;

    int check = 0;
    for(int i = 0; i < 26; i++) check += (a[i] % 2);

    if(check > 1){
        cout << "NO SOLUTION";
        return 0;
    }

    string result;
    for (int i = 0; i < 26; i++){
        if(!(a[i]%2)){
            for(int j = 0; j < a[i]/2; j++) result.push_back(i + 'A');
        }
    }
    for (int i = 0; i < 26; i++){
        if(a[i]%2){
            for(int j = 0; j < a[i]; j++) result.push_back(i + 'A');
        }
    }
    for (int i = 25; i >= 0; i--){
        if(!(a[i]%2)){
            for(int j = 0; j < a[i]/2; j++) result.push_back(i + 'A');
        }
    }

    cout << result << endl;
    return 0;
}
```
