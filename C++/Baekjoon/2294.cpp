#include <iostream>
#define MAX 200
#define INF 123456789
using namespace std;

int value[MAX];
int dp[100001];

int main(){
    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> value[i];
    }
    
    for(int i = 1; i <= k; i++) {
        dp[i] = INF;
    }
    value[0] = 0;
    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = value[i]; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - value[i]] + 1);
        }
    }

    if (dp[k] == INF ) cout << -1;
    else cout << dp[k];
}