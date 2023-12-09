#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    char op;
    cin >> a >> op >> b;

    int la = a.size(), lb = b.size();

    if (la == lb && op == '+') cout << 2;
    else cout << 1;

    if (op == '+') {
        for (int i = 1; i < max(la, lb); i++) {
            if (i == max(la, lb) - la || i == max(la, lb) - lb) cout << 1;
            else cout << 0;
        }
    } else {
        for (int i = 0; i < la + lb - 2; i++) cout << 0;
    }
}
