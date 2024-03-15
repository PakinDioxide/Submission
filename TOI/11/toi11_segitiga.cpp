#include <bits/stdc++.h>

using namespace std;

int op[3][3] = {{2, 1, 0}, {2, 1, 1}, {1, 2, 1}};
map <vector <int>, pair <bool, bool>> dp;

bool solve(vector <int> s) {
    if (dp[s].first) return dp[s].second;
    if (s[0] != 0) {dp[s] = {1, 0}; return false;}
    if (s.size() == 1) {
        if (s[0] == 0) {dp[s] = {1, 1}; return true;}
        else {dp[s] = {1, 0}; return false;}
    }
    for (int i = 0; i < s.size() - 1; i++) {
        int k = op[s[i]][s[i+1]], a = s[i], b = s[i+1];
        s.erase(s.begin()+i);
        s.erase(s.begin()+i);
        s.insert(s.begin()+i, k);
        if (solve(s)) {dp[s] = {1, 1}; return true;}
        else dp[s] = {1, 0};
        s.erase(s.begin()+i);
        s.insert(s.begin()+i, b);
        s.insert(s.begin()+i, a);
    }
    dp[s] = {1, 0};
    return false;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 0; i < 20; i++) {
        int n;
        string k;
        cin >> n >> k;
        vector <int> s(n);
        for (int i = 0; i < n; i++) s[i] = k[i] - '0';
        if (solve(s)) cout << "yes\n";
        else cout << "no\n";
    }
}
