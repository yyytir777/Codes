#include <iostream>
#define MAX 10000
using namespace std;

int D[MAX][MAX];

int Floyd_Wareshall(int n) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (D[i][k] + D[k][j] < D[i][j])
                    D[i][j] = D[i][k] + D[k][j];
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> D[i][j];
        }
    }

    Floyd_Wareshall(n);

        
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << D[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}