#include <iostream>
using namespace std;

long long fibo(long long n){
    long long dp[n];
    dp[0] = 0;
    if(n > 0){
        dp[1] = 1;
        for(long long i = 2; i <= n; i++){
            dp[i] = dp[i-2] + dp[i-1];
        }
    }
    return dp[n];
}

int main(){
    cout << fibo(5000);    
    return 0;
}