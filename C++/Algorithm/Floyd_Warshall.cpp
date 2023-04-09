#include <iostream>
using namespace std;


int Floyd_Wareshall(int n, int (*D)[n]){
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; i++)
                if(D[i][k] + D[k][j] < D[i][j])
                    D[i][j] = D[i][k] + D[k][j];
}