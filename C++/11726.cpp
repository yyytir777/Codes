#include <iostream>
#define MAX 1001
using namespace std;

int dp[MAX] = {0,};

int main() {
    int n;
    cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 0; i <= n; i++) {
        if (i > 2) {
            dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;
        }
    }


    cout << dp[n] % 10007;
}

/*
dp[1] = 1
dp[2] = 2
dp[3] = 1 + 2 = 3
dp[4] = 1 + 3 + 1 = 5
dp[5] = 1 + 4 + 3 = 8
dp[6] = 

dp[i] = dp[i - 2] * + dp[i - 1]
*/