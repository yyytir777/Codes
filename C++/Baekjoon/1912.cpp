#include <iostream>
#include <algorithm>
using namespace std;

#define M 100001
int arr[M];
int dp[M] = {0};
int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        dp[i] = arr[i];
    }

    int m = arr[0];
    dp[0] = arr[0];
    for(int i = 1; i <= n; i++){
        dp[i] = max(dp[i], dp[i-1] + arr[i]);
        if(m < dp[i-1]){
            m = dp[i-1];
        }
    }
    cout << m;
    return 0;
}