#include <bits/stdc++.h>

using namespace std;

string m[3], n[3];

int check(string a, string b, string c) {
    if (a == "   ") {
        if (b == "  |") return 1;
        else return 4;
    } else if (b ==" _|") {
        if (c == "|_ ") return 2;
        else return 3;
    } else if (b == "|_ ") {
        if (c == " _|") return 5;
        else return 6;
    } else if (b == "  |") return 7;
    else if (b == "|_|") {
        if (c == "|_|") return 8;
        else return 9;
    } else return 0;
}

int main() {
    int a, b;

    cin >> a >> b;
    getchar();

    for (int i = 0; i < 3; i++) getline(cin, m[i]);
    for (int i = 0; i < 3; i++) getline(cin, n[i]);

    long long ans = 0;

    for (int i = 0; i < a; i++) {
        ans += pow(10, a-i-1) * check(m[0].substr(4*i, 3), m[1].substr(4*i, 3), m[2].substr(4*i, 3));
    }
    for (int i = 0; i < b; i++) {
        ans += pow(10, b-i-1) * check(n[0].substr(4*i, 3), n[1].substr(4*i, 3), n[2].substr(4*i, 3));
    }

    cout << ans;
}
