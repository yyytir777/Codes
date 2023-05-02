#include <iostream>
using namespace std;

#define INF 987654321 // <-- 가중치와 차이가 많이 나는 정수여야함
#define MAX 101
int w[MAX][MAX] = {0,};  // i에서 j까지 가는 최단거리

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int x, y, cost; //시작도시, 도착도시, 비용
        cin >> x >> y >> cost;
        if(w[x][y] == 0 || w[x][y] > cost)
            w[x][y] = cost;
    }

    int d[MAX][MAX];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j)
                d[i][j] = 0;
            else if(w[i][j]) //w[i][j]가 0이 아닐때
                 d[i][j] = w[i][j];
            else
                d[i][j] = INF;
        }
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j || d[i][j] == INF)
                cout << 0 << " ";
            else
                cout << d[i][j] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}