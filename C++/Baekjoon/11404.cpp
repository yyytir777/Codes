#include <iostream>
using namespace std;

int d[101][101];  // i에서 j까지 가는 최단거리

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int x, y, cost;
        cin >> x >> y >> cost;
        d[x][y] = cost;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << d[i][j] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}
