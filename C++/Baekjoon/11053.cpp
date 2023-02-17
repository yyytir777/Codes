#include <iostream>
using namespace std;

#define M 1001

int arr[M];
int dp[M] = {0,};

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    int max_dp = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = 1;
        for(int j = i - 1; j >= 1; j--){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_dp = max(dp[i], max_dp);
    }
    cout << max_dp;
    return 0;
}