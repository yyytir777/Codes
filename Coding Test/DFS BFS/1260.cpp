#include <iostream>
#include <queue>
#define MAX_N 1001
using namespace std;

int graph[MAX_N][MAX_N] = {-1,};
bool state[MAX_N] = {0,};

int n;
int m;
int v;
queue<int> q;

void dfs(int v) {
    state[v] = true;
    cout << v << " ";

    for(int i = 1; i < n+1; i++) {
        if(graph[v][i] == 1 && state[i] == false){
            dfs(i);
        }
    }
}

void bfs(int v){
    state[v] = true;
    q.push(v);

    while(!q.empty()) {
        v = q.front();
        q.pop();
        cout << v << " ";

        for(int i = 1; i < n+1; i++) {
            if(graph[v][i] == 1 && state[i] == false) {
                q.push(i);
                state[i] = true;
            }
        }
    }

}

void init() {
    for(int i = 0; i < n + 1; i++) {
        state[i] = 0;
    }
}
int main() {
    
    cin >> n >> m >> v;

    int temp_x, temp_y;
    for(int i = 0; i < m; i++) {
        cin >> temp_x >> temp_y;
        graph[temp_x][temp_y] = 1;
        graph[temp_y][temp_x] = 1;
    }

    init();
    dfs(v);
    cout << endl;

    init();
    bfs(v);
    cout << endl;
    return 0;
}