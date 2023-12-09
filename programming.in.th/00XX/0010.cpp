#include <bits/stdc++.h>

using namespace std;

int main() {
    string t;
    cin >> t;
    int p = 1;

    for (auto i : t) {
        if (i == 'A') {
            if (p == 1) p = 2;
            else if (p == 2) p = 1;
        } else if (i == 'B') {
            if (p == 2) p = 3;
            else if (p == 3) p = 2;
        } else {
            if (p == 1) p = 3;
            else if (p == 3) p = 1;
        }
    }

    cout << p;
}
