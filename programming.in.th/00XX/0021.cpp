#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    int n = s.size();

    for (int i = 0; i < n; i++) {
        cout << s[i];
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') i+=2;
    }
}
