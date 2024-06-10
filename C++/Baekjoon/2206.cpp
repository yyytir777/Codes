#include <bits/stdc++.h>
#define MAX 1001
#define INF 987654321
using namespace std;

int N, M, min_dist = INF;
int graph[MAX][MAX];
int dist[MAX][MAX];
bool visited[MAX][MAX] = {0,};

int row_axis[4] = {1,-1,0,0};
int col_axis[4] = {0,0,-1,1};

queue<pair<int, int>> q;
vector<int> v;
vector<pair<int, int>> wall_v;

void init() {
    memset(visited, 0, sizeof(visited));
    memset(dist, 0, sizeof(dist));
    
    while(!q.empty()) {
        q.pop();
    }
}

void bfs(int start, int end){
    q.push({start, end});
    visited[start][end] = 1;
    dist[start][end] = 1;

    if(start == N && end == M) {
        v.push_back(dist[start][end]);
        if(min_dist > dist[start][end]) min_dist = dist[start][end];
        return;
    }

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        // cout << "route : (" << r << ", " << c << ")\n";

        for(int i = 0; i < 4; i++){
            int nxt_row = r + row_axis[i];
            int nxt_col = c + col_axis[i];

            if(nxt_row <= 0 || nxt_row > N || nxt_col <= 0 || nxt_col > M) continue;
            if(graph[nxt_row][nxt_col] != 1 && !visited[nxt_row][nxt_col]){
                visited[nxt_row][nxt_col] = 1;
                q.push({nxt_row, nxt_col});
                dist[nxt_row][nxt_col] = dist[r][c] + 1;

                if(nxt_row == N && nxt_col == M) {
                    v.push_back(dist[nxt_row][nxt_col]);
                    if(min_dist > dist[nxt_row][nxt_col]) min_dist = dist[nxt_row][nxt_col];
                    // cout << "dist : " << dist[nxt_row][nxt_col] << '\n';
                    return;
                }
            }
        }
    }
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
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(graph[i][j] == 1) wall_v.push_back({i, j});
        }
    }

    for(pair<int, int> tmp : wall_v) {
        
        int r = tmp.first;
        int c = tmp.second;

        // cout << "wall : (" << r << ", " << c << ")\n";

        graph[r][c] = 0;
        bfs(1, 1);
        init();
        graph[r][c] = 1;
    }

    bfs(1, 1);

    if(min_dist == INF) cout << "-1";
    else cout << min_dist;
}