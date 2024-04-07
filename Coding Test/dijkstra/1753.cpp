#include <iostream>
#define MAX 20001
#define INF 12345678
using namespace std;

int graph[MAX][MAX] = {INF,};
int V, E;
int K;
void input(){
    cin >> V >> E;

    cin >> K;

    int u, v, w;
    for(int i = 1; i <= V; i++) {
        cin >> u >> v >> w;
        if(graph[u][v] > w)
            graph[u][v] = w;
    }

    for(int i = 1; i <= V; i++) {
        for(int j = 1; j <= V; j++) {
            cout << graph[i][j] << " ";
        }
        cout <<endl;
    }
}

int main() {
    input();
}