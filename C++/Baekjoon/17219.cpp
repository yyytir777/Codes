#include <bits/stdc++.h>
using namespace std;

map<string, string> m_map;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    string url, password;
    for(int i = 0; i < n; i++) {
        cin >> url >> password;
        m_map.insert({url, password});
    }

    for(int i = 0; i < m; i++) {
        cin >> url;

        cout << m_map[url] << '\n';
    }
}