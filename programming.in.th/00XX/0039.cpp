#include <bits/stdc++.h>

using namespace std;

int n, l;
vector <int> food;
vector <bool> no;
vector <vector <int>> ans;

void recur (int c, vector <int> order, vector <bool> alr) {
    if (c == n) {
        ans.push_back(order);
        return;
    }

    for (auto i : food) {
        if ((c > 0 && !alr[i]) || (c == 0 && !no[i])) {
            order[c] = i;
            alr[i] = true;
            recur(c+1, order, alr);
            alr[i] = false;
        }
    }
}

int main() {
    cin >> n >> l;

    no.resize(n);

    for (int i = 0; i < n; i++) {food.push_back(i);}

    for (int i = 0; i < l; i++) {
        int a;
        cin >> a;
        no[a-1] = true;
    }

    vector <int> t(n);
    vector <bool> tt(n);

    recur(0, t, tt);

    for (auto i : ans) {
        for (auto j : i) cout << j + 1 << ' ';
        cout << '\n';
    }
}
