#include <bits/stdc++.h>

using namespace std;

void solve(string s, int k) {
    if (k == 0) {
        cout << s << "E\n";
        return;
    }
    solve(s+"--\n", k-1);
    if (k > 1) solve(s+"||\n", k-2);
}

int main() {
    int n;
    cin >> n;
    solve("", n);
}
