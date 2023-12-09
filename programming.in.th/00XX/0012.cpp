#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0) cout << "..*.";
        else cout << "..#.";
    }
    cout << ".\n";

    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0) cout << ".*.*";
        else cout << ".#.#";
    }
    cout << ".\n";

    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 || (i % 3 == 1 && i >= 4)) cout << "*." << s[i-1] << ".";
        else cout << "#." << s[i-1] << ".";
    }

    if (n % 3 == 0) cout << "*\n";
    else cout << "#\n";

    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0) cout << ".*.*";
        else cout << ".#.#";
    }
    cout << ".\n";

    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0) cout << "..*.";
        else cout << "..#.";
    }
    cout << ".\n";
}
