#include <iostream>
#include <algorithm>
using namespace std;

#define N 1001
#define R 0
#define G 1
#define B 2

int arr[N][3]; //R G B
int cost[N][3] = {0}; //RGB별 cost

int main(){
    int n;
    cin >> n;

    //배열 생성
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < 3; i++){
        cost[0][i] = arr[0][i];
    }
    
    for(int i = 1; i < n; i++){
        cost[i][0] = min(cost[i-1][1], cost[i-1][2]) + arr[i][0];
        cost[i][1] = min(cost[i-1][0], cost[i-1][2]) + arr[i][1];
        cost[i][2] = min(cost[i-1][0], cost[i-1][1]) + arr[i][2];
    }


    cout << min(min(cost[n-1][0], cost[n-1][1]), cost[n-1][2]);
    return 0;
}