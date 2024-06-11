#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int N, M;
int graph[MAX][MAX];
bool visited[MAX][MAX][2];

int row_axis[4] = {1,-1,0,0};
int col_axis[4] = {0,0,-1,1};

//                           crashed, dist
queue<pair<pair<int, int>, pair<int, int>>> q;

int bfs(int start, int end){
    visited[start][end][0] = 1;
    visited[start][end][1] = 1;
    q.push({{start, end}, {0, 1}});

    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int crashed = q.front().second.first;
        int dist = q.front().second.second;
        q.pop();

        if(r == N && c == M) return dist;

        for(int i = 0; i < 4; i++){
            int nxt_row = r + row_axis[i];
            int nxt_col = c + col_axis[i];

            if(nxt_row <= 0 || nxt_row > N || nxt_col <= 0 || nxt_col > M) continue;
            if(!visited[nxt_row][nxt_col][crashed]){ // 방문 안했을 때

                if(graph[nxt_row][nxt_col] && !crashed) { // 벽이며 벽을 부수지 않은 경우
                    visited[nxt_row][nxt_col][crashed] = 1;
                    q.push({{nxt_row, nxt_col}, {1, dist + 1}});
                }
                else if(!graph[nxt_row][nxt_col]) { //벽이 아닌 경우
                    visited[nxt_row][nxt_col][crashed] = 1;
                    if(crashed) { //이미 부순 경우
                        q.push({{nxt_row, nxt_col}, {1, dist + 1}});
                    }
                    else { //부수지 않은 경우
                        q.push({{nxt_row, nxt_col}, {0, dist + 1}});
                    }
                }
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        string tmp;
        cin >> tmp;   
        for(int j = 1; j <= M; j++){
            graph[i][j] = tmp[j - 1] - 48;
        }
    }
    cout << bfs(1, 1);
}