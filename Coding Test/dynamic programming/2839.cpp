#include <iostream>
using namespace std;

int dp[5001] = {0,};

int main(){
    int N;
    cin >> N;

    dp[3] = 1;
    dp[5] = 1;

    dp[n] = min(dp[n-3] + 1, dp[n-5] + 1);
}