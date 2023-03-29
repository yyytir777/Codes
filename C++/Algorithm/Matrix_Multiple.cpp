#include <iostream>
using namespace std;

void matrixmult(int n, int (*a)[3], int (*b)[3], int (*c)[3]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            c[i][j] = 0;
            for(int k = 0; k < n; k++){
                c[i][j] = c[i][j] + a[i][k] + b[k][j];
            }
        }
    }
}

int main(){
    int a[3][3] = {{1,1,1}, {2,2,2}, {3,3,3}};
    int b[3][3] = {{1,2,3}, {1,2,3}, {1,2,3}};
    int c[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};

    matrixmult(3, a, b, c);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << c[i][j];
            if(j < 2) cout << " ";
        }
        cout << '\n';
    }
    return 0;
}