#include <bits/stdc++.h>

using namespace std;

int main() {
    double x = 0, y = 0;

    string s;

    cin >> s;

    while (s != "*") {
        string ss, k;
        double t = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') ss.push_back(s[i]);
            else k.push_back(s[i]);
        }
        for (int i = 0; i < ss.size(); i++) t += (s[ss.size()-i-1]-'0')*pow(10, i);

        double r = sqrt(t*t/2);

        if (k == "N") y += t;
        else if (k == "S") y -= t;
        else if (k == "W") x -= t;
        else if (k == "E") x += t;
        else if (k == "NE") {x += r; y += r;}
        else if (k == "NW") {x -= r; y += r;}
        else if (k == "SE") {x += r; y -= r;}
        else {x -= r; y -= r;}
        cin >> s;
    }

    printf("%.3lf %.3lf\n%.3lf", x, y, sqrt(x*x+y*y));
}
