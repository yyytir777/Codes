#include <iostream>
#define MAX 5
#define INF 987654321
using namespace std;

int adj[MAX][MAX];
bool state[MAX] = {0,};

int dfs(int i){

}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            adj[i][j] = INF;
        }
    }

    int s, e, l;
    for(int i = 0; i < m; i++){
        cin >> s >> e >> l;
        if(adj[s][e] == INF || adj[s][e] > l)
            adj[s][e] = l;
    }

    for (int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(adj[i][j] > adj[i][k] + adj[k][j] && (adj[i][j] != INF || adj[i][k] != INF || adj[k][j] != INF))
                    adj[i][j] = adj[i][k] + adj[k][j];
            }
        }
    }

    for(int i = 0; i < n; i++){
        
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << adj[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}