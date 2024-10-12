#include <bits/stdc++.h>
#define MAX 10000
using namespace std;

/*

dp[n] : n까지 가장 짧은 길
지름길이 없을 때 -> dp[n] = dp[n-1] + 1
지름길이 있을 때 -> dp[n] = min(dp[n-1] + 1, dp[start] + cost)


*/
vector<pair<int, int>> v[MAX];
int dp[MAX];

int main() {
    int n, d;
    cin >> n >> d;

    int start, end, l;
    for(int i = 0; i < n; i++) {
        cin >> start >> end >> l;
        if(end - start < l || end > d) continue;
        v[end].push_back({start, l});
    }

    dp[0] = 0;

    for(int i = 1; i <= d; i++) {
        dp[i] = dp[i-1] + 1;
        for(int j = 0; j < i; j++) {
            
        }
    }
    cout << dist[n];
    return 0;
}