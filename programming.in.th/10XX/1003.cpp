#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    cin >> n;

    set <int> nug;

    for (int i = 0; i <= n/6; i++) {
        for (int j = 0; j <= n/9; j++) {
            for (int k = 0; k <= n/20; k++) {
                int nugg = 6*i + 9*j + 20*k;

                if (nugg != 0 && nugg <= n) nug.insert(nugg);
            }
        }
    }

    if (nug.empty()) cout << "no";

    for (auto i : nug) cout << i << '\n';
}
