#include <bits/stdc++.h>

using namespace std;

int k, a, b, n;

void solve(int c, int w, int l, string s) {
    if (c == n || w == k || l == k) {cout << s << '\n'; return;}
    solve(c+1, w+1, l, s+"W ");
    solve(c+1, w, l+1, s+"L ");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> k >> a >> b;
    n = 2*k-1;
    solve(a+b, a, b, "");
}
