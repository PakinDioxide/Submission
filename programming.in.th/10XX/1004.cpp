#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, n;
    cin >> k >> n;

    vector <int> room(10001);

    for (int i = 0; i < n; i++) {
        int a, b;

        cin >> a >> b;

        room[b] = a;
    }

    vector <pair <int, int>> q;

    char t;
    cin >> t;

    while (t != 'X') {
        if (t == 'D') {
            if (!q.empty()) {
                cout << q[0].second << '\n';
                q.erase(q.begin());
            } else cout << "empty\n";
        } else if (t == 'E'){
            int a, r, done = 0;
            cin >> a;

            r = room[a];

            for (int i = q.size()-1; i >= 0; i--) {
                if (q[i].first == r) {
                    i++;
                    q.insert(q.begin()+i, {r, a});
                    done = 1;
                    break;
                }
            }

            if (!done) q.push_back({r, a});
        }
        cin >> t;
    }
    cout << 0;
}
