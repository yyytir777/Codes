// 9252 cpp
#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

string a, b;
int dp[MAX][MAX] = {0,};

void print_dp() {
    for(int i = 1; i <= a.length(); i++) {
        for(int j = 1; j <= b.length(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }
}

void input() {
    cin >> a;
    cin >> b;
}

/*
dp[i][j] => a(0, i), b(0, j)의 LCS길이
a[i] == b[j]이면, dp[i][j] = dp[i-1][j-1] + 1
a[i] != b[j]이면, dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

*/

void solve() {

    for(int i = 1; i <= a.length(); i++){
        for(int j = 1; j <= b.length(); j++) {
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    string ans;
    

    int i = a.length(), j = b.length();
    while(i > 0 && j > 0) {
        if(dp[i-1][j] == dp[i][j]) i--;
        else if(dp[i][j-1] == dp[i][j]) j--;
        else {
            ans = a[i-1] + ans;
            i--; j--;
        }
    }

    int len = dp[a.length()][b.length()];
    cout << len << '\n';
    if(len != 0) cout << ans;
}

int main() {
    input();
    solve();
    return 0;
}