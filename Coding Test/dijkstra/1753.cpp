#include <iostream>
#define MAX 20001
#define INF 87654321
using namespace std;

int graph[MAX][MAX];
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
}

int main() {
    input();
}