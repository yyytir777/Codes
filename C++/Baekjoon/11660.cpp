#include <bits/stdc++.h>
#define MAX 1025
using namespace std;
int N, M;
int arr[MAX][MAX];
int dp[MAX][MAX];

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << dp[x2][y2] - dp[x1][y1] + arr[x1][y1];
}

int main() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            
        }
    }

    while(M--) {
        solve();
    }
}