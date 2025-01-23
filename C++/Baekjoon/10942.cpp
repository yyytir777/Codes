// 10942 cpp
#include <bits/stdc++.h>
#define MAX 2001
using namespace std;

int n, m;
int arr[MAX];
vector<pair<int, int>> v;
bool dp[MAX][MAX] = {0,};

void input() {
    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> arr[i];

    cin >> m;
    int s, e;
    for(int i = 0; i < m; i++) {
        cin >> s >> e;
        v.push_back({s, e});
    }
}

void calc_dp() {
    for(int i = 1; i <= n; i++) dp[i][i] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n && j + i <= n; j++) {
            // printf("%d %d\n", j, j+i);

            if(arr[j] != arr[j + i]) continue;

            if(i == 1 || i == 2) dp[j][j + i] = 1;
            else if(i > 2) {
                if(dp[j + 1][j + i - 1] == 1) dp[j][j + i] = 1;
            }
        }
    }
}

void print_dp() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }
}

void print_arr() {
    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';
}

void solve() {
    calc_dp();

    // print_dp();

    int s, e;
    for(int i = 0; i < m; i++) {
        s = v[i].first;
        e = v[i].second;
        // cout << s << " : " << e << '\n';
        cout << dp[s][e] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
    return 0;
}