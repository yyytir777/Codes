#include <iostream>
#include <algorithm>
using namespace std;

#define N 501

int arr[N][N];
int dp[N][N] = {0,};
// 왼쪽 오른쪽 중 최댓값을 골라야함 -> algorithm 헤더파일 추가(max)

int main(){
    int n;
    cin >> n;

    //배열 삽입
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cin >> arr[i][j];
        }
    }

    dp[0][0] = arr[0][0];
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j];
        }
    }

    int max = 0;
    for(int i = 0; i < n; i++){
        if(max < dp[n-1][i]){
            max = dp[n-1][i];
        }
    }
    cout << max;
    return 0;
}