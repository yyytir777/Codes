#include <iostream>
using namespace std;

int main(){
    
    return 0;
}

int knapsack(int capacity, int w[], int v[], int n){
    int K[n+1][capacity+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= capacity; j++){
            if(i == 0 || j == 0)
                K[i][j] = 0;
            else if(w[i-1] <= j)
                K[i][j] = max(K[i-1][j], v[i-1] + K[i-1][j - w[i-1]]);
            else
                K[i][j] = K[i-1][j];
        }
    }
    return K[n][capacity];
}