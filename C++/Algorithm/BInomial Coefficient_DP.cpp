#include <iostream>
using namespace std;

int cnt = 0;

int bin(int n, int k){
    int B[n+1][k+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= min(i,k); j++){
            if(j == 0 || i == 0){
                cnt += 1;
                B[i][j] = 1;
            }
            else{
                cnt += 2;
                B[i][j] = B[i-1][j-1] + B[i-1][j];
            }
        }
    }
    return B[n][k];
}

int main(){
    bin(100, 3);
    cout << cnt;
}