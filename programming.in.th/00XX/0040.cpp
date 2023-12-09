#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char a[1001];
        cin >> a;
        if ((strlen(a) == 1 && a[strlen(a)-1] == '2') || a[strlen(a)-1] % 2 == 1) cout << "T\n";
        else cout << "F\n";
    }
}
