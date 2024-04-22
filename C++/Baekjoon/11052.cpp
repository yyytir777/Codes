#include <iostream>
using namespace std;

#define N 1001

int p[N];
int dp[N];

/*
P(n) : n개를 갖기 위해 지불해야하는 금액의 최댓값

P(n) = max(P(n-1) + p1, P(n-2) + p2, P(n-3) + p3 ...)

dp(1) = p(1)
dp(2) = max(dp(1) + p(1), dp(0) + p(2))
*/

int main(){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> p[i];
    }
    p[0] = 0;
    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        int max = 0;
        for(int j = 1; j <= i; j++) {
            if(max < dp[i-j] + p[j]) {
                max = dp[i-j] + p[j];
            }
        }
        dp[i] = max;
    }

    cout << dp[n] << endl;

    return 0;
}