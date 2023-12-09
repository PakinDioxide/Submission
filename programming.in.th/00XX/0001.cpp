#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;

    cin >> a >> b >> c;

    int grade = (a+b+c)/5;

    if (grade >= 16) cout << "A";
    if (grade < 10) cout << "F";

    switch (grade)
    {
    case 15:
        cout << "B+";
        break;
    case 14:
        cout << "B";
        break;
    case 13:
        cout << "C+";
        break;
    case 12:
        cout << "C";
        break;
    case 11:
        cout << "D+";
        break;
    case 10:
        cout << "D";
        break;
    }
}
