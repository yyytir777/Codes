#include <iostream>
using namespace std;

int bin(int n, int k){
    int B[n][k];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(j == 0 || i == 0)
                B[i][j] = 1;
            else
                B[i][j] = B[i-1][j-1] + B[i-1][j];
        }
    }
    return B[n][k];
}