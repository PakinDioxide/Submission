#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < 2*n-1; i++) {
        for (int j = 0; j < 4*n+3; j++) {
            if (i == 0) {
                if ((j+1)%(n+1)==0||j==4*n+2) cout << ' ';
                else cout << '#';
            } else if (i < n-1) {
                if (j % (n+1) == 0 || (j > n && j % (n+1) == n-1)) cout << '#';
                else cout << ' ';
            } else if (i == n-1) {
                if (j < n || (j > 2*(n+1)-1 && j < 3*(n+1)-1) || j % (n+1) == 0 || j % (n+1) == n-1) cout << '#';
                else cout << ' ';
            } else if (i < 2*n-2) {
                if (j % (n+1) == 0 || j == 2*n || j == 4*n+2 || j == 2*(n+1)+(i-n)+1) cout << '#';
                else cout << ' ';
            } else {
                if ((j+1)%(n+1)==0||j==4*n+2||(j > 2*(n+1) && j < 2*(n+1)+n-1)||(j>0&&j<n)) cout << ' ';
                else cout << '#';
            }
        }
        cout << '\n';
    }
}
