#include <iostream>
using namespace std;

void exchange(int i, int j, int *S){
    int tmp = *(S + i);
    *(S + i) = *(S + j);
    *(S + j) = tmp; 
}

void exchange_sort(int n, int *S){
    for(int i = 0; i < n-1; i++){
        for(int j = i + 1; j < n; j++){
            if(S[j] < S[i]){
                exchange(i, j, S);
            }
        }
    }
}

int main(){
    int S[9] = {6,8,3,7,5,1,2,9,4};
    exchange_sort(9, S);

    for(int i = 0; i < 9; i++){
        cout << S[i] << " ";
    }
    return 0;
}