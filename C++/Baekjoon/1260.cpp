#include <iostream>
#include <queue>
#define n 1001
using namespace std;

int N, M, V;
//정점의 개수, 간선의 개수, 탐색 시작할 정점의 번호

int adj_matrix[n][n];
//인접 행렬
bool state[n] = {0,};
//방문했으면 1, 방문하지 않았으면 0

queue<int> q;

void init(){
    for(int i = 0; i < n; i++){
        state[i] = 0;
    }
}

void DFS(int v){
    state[v] = true;
    cout << v << ' ';

    for(int i = 1; i <= N; i++){
        if(adj_matrix[v][i] == 1 && state[i] == false){ //정점과 연결되어있고 방문X
            DFS(i);
        }
    }
}

void BFS(int v){
    q.push(v);
    state[v] = true;

    while(!q.empty()){
        v = q.front();
        q.pop();
        cout << v << " ";
        //pop하면서 원소 출력

        for(int j = 1; j <= N; j++){
            if(adj_matrix[v][j] == 1 && state[j] == false){ //정점과 연결되어있고 방문X여야함
                q.push(j);
                state[j] = true;
            }
        }
    }
}

int main(){
    
    cin >> N >> M >> V;

    //edge 설정
    for(int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;

        //index로 변환
        adj_matrix[x][y] = 1;
        adj_matrix[y][x] = 1;
    }
    
    /*
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << adj_matrix[i][j] << " ";
        }
        cout << "\n"; 
    }
    */

    init();
    DFS(V);
    cout << '\n';
    init();
    BFS(V);

    return 0;
}