#include <iostream>
#define MAX 502
#define INF 987654321
using namespace std;

int adj[MAX][MAX] = {INF,};

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            adj[i][j] = INF;
        }
    }

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
    }

    for(int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if(adj[i][j] > adj[i][k] + adj[k][j])
                    adj[i][j] = adj[i][k] + adj[k][j];
            }
        }
    }

    int temp = 0;
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(adj[i][j] != INF || adj[j][i] != INF)
                cnt++;
        }
        if(cnt == (n - 1))
            temp++;
    }
    cout << temp;
    return 0;
}