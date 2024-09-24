#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int arr[MAX];
int up_dp[MAX];
int down_dp[MAX];

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        up_dp[i] = 1;
        down_dp[i] = 1;
    }

    int max_idx = 0;
    for(int i = 1; i < n; i++) {
        if(arr[i-1] < arr[i]) {
            max_idx = max(max_idx, i);
            up_dp[i] = up_dp[i-1] + 1;
        }
        else {
            up_dp[i] = up_dp[i-1];
        }
    }
    
    for(int i = max_idx; i < n; i++) {
        if(arr[i-1] > arr[i]) {
            down_dp[i] = down_dp[i-1] + 1;
        }
        else {
            down_dp[i] = down_dp[i-1];
        }
    }

    cout << up_dp[n-1] + down_dp[n-1] - 1;
    return 0;
}