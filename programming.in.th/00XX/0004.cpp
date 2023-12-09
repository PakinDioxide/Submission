#include <bits/stdc++.h>

using namespace std;

int main() {
    string t;
    cin >> t;
    bool s, c;
    s = c = false;

    for (auto i : t) {
        if (i <= 'Z') c = true;
        else s = true;
        if (c && s) break;
    }

    if (c && s) cout << "Mix";
    else if (c) cout << "All Capital Letter";
    else cout << "All Small Letter";
}
