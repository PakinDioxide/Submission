#include <bits/stdc++.h>

using namespace std;

int main() {
    string n;
    cin >> n;
    long long t = 0, e = 0;

    for (int i = 0; i < n.size(); i++) {
        t *= 10;
        t += n[i]-'0';
        t %= 3;
        e *= 10;
        e += n[i]-'0';
        e %= 11;
    }

    cout << t%3 << " " << e%11;
}
