#include <bits/stdc++.h>

using namespace std;

int main() {
    set <int> rem;

    for (int i = 0; i < 10; i++) {
        int a;
        cin >> a;
        rem.insert(a%42);
    }

    cout << rem.size();
}
