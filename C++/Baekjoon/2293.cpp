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

    for(int i = 0; i < k; i++){
        while(dp[i] == k){
            if(dp[i] > k) continue;
            
        }
    }
    return 0;
}