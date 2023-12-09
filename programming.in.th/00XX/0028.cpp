#include <bits/stdc++.h>

using namespace std;

struct t {
    string name;
    int a = 0;
    int b = 0;
    int c = 0;
};

int main() {
    struct t team[4];

    for (int i = 0; i < 4; i++) cin >> team[i].name;

    int m[4][4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> m[i][j];

            team[i].a += m[i][j];
            team[i].b += m[i][j];
            team[j].b -= m[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i != j) {
                if (m[i][j] > m[j][i]) team[i].c += 3;
                else if (m[i][j] == m[j][i]) team[i].c += 1;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = i+1; j < 4; j++) {
            if (team[i].c < team[j].c) {
                struct t temp = team[i];
                team[i] = team[j];
                team[j] = temp;
            } else if (team[i].c == team[j].c) {
                if (team[i].b < team[j].b) {
                    struct t temp = team[i];
                    team[i] = team[j];
                    team[j] = temp;
                } else if (team[i].b == team[j].b) {
                    if (team[i].a < team[j].a) {
                        struct t temp = team[i];
                        team[i] = team[j];
                        team[j] = temp;
                    }
                }
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        cout << team[i].name << " " << team[i].c << "\n";
    }
}
