#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    stack <uint8_t> st;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        if (s[i] == 'T') {
            string nn;
            i++;
            while (s[i] >= '0' && s[i] <= '9') {
                nn += s[i];
                i++;
            }
            i--;
            st.push((uint8_t)stoi(nn));
        } else if (s[i] == 'P') {
            st.pop();
        } else if (s[i] == 'A') {
            uint8_t a = st.top();
            st.pop();
            uint8_t b = st.top();
            st.pop();
            st.push((uint8_t) a+b);
        } else if (s[i] == 'S') {
            uint8_t a = st.top();
            st.pop();
            uint8_t b = st.top();
            st.pop();
            st.push((uint8_t)a-b);
        } else if (s[i] == 'M') {
            uint8_t a = st.top();
            st.pop();
            uint8_t b = st.top();
            st.pop();
            st.push((uint8_t)a*b);
        } else if (s[i] == 'B') {
            cout << (int) st.top() << '\n';
        }
    }
}
