#include <iostream>
using namespace std;

#define MAX 501
int d[MAX + 1] = {0,};

int main(){
    int n, r, c;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> r >> c;
        d[i] = r, d[i+1] = c;
    }
    
    int m[MAX][MAX] = {0,};

    for(int i = 1; i <= n; i++){
        m[i][i] = 0;
    }

    for (int diagonal = 1; diagonal <= n - 1; diagonal++){
        for (int i = 1; i <= n - diagonal; i++){
            int j = i + diagonal;
            int min = m[i][i] + m[i+1][j] + d[i-1] * d[i] * d[j];
            for (int k = i + 1; k < j; k++){
                if(min > m[i][k] + m[k+1][j] + d[i-1] * d[k] * d[j])
                    min = m[i][k] + m[k+1][j] + d[i-1] * d[k] * d[j];
            }
            m[i][j] = min;
        }
    }

    cout << m[1][n];
    return 0;
}