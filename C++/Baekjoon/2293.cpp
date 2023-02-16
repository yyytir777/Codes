#include <iostream>
using namespace std;

#define N 101
#define K 10001

int dp[K] = {0,};
int coin[N];

int main(){
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> coin[i];
    }

    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = coin[i]; j <= k; j++){
            dp[j] += dp[j - coin[i]]; 
        }
    }

    cout << dp[k];
    return 0;
}