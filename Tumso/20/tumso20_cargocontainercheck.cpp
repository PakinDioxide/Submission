#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        long long sum = 0;
        for (int j = 0; j < 4; j++) {
            if (s[j] == 'A') sum += pow(2, j)*10;
            else if (s[j] >= 'B' && s[j] <= 'K') sum += pow(2, j)*(s[j] - 'B' + 12);
            else if (s[j] >= 'L' && s[j] <= 'U') sum += pow(2, j)*(s[j] - 'L' + 23);
            else if (s[j] >= 'V' && s[j] <= 'Z') sum += pow(2, j)*(s[j] - 'V' + 34);
        }
        for (int j = 4; j < 10; j++) sum += pow(2, j)*(s[j] - '0');

        sum %= 11;
        if (sum == (s[10]-'0')) cout << s << '\n';
    }
}
