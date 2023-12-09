#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int a = 0, b = 0, c = 0;

    for (int i = 0; i < n; i++) {
        if (i % 3 == 0 && s[i] == 'A') a++;
        else if (i % 3 == 1 && s[i] == 'B') a++;
        else if (i % 3 == 2 && s[i] == 'C') a++;

        if ((i % 4 == 0 || i % 4 == 2) && s[i] == 'B') b++;
        else if (i % 4 == 1 && s[i] == 'A') b++;
        else if (i % 4 == 3 && s[i] == 'C') b++;

        if ((i % 6 == 0 || i % 6 == 1) && s[i] == 'C') c++;
        else if ((i % 6 == 2 || i % 6 == 3) && s[i] == 'A') c++;
        else if ((i % 6 == 4 || i % 6 == 5) && s[i] == 'B') c++;
    }

    int m = max({a, b, c});
    cout << m << '\n';
    if (a == m) cout << "Adrian\n";
    if (b == m) cout << "Bruno\n";
    if (c == m) cout << "Goran\n";
}
