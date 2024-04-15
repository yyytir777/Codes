#include <iostream>
#include <queue>
#define MAX 51
using namespace std;

bool arr[MAX][MAX] = {0,};
bool state[MAX][MAX] = {0,};

queue<pair<int, int>> q;

int axis_x[4] = {1,-1,0,0};
int axis_y[4] = {0,0,-1,1};

void bfs(int N, int M, int K) {
    int cnt = 0;
    for(int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(arr[i][j] == 1 && state[i][j] == false) {
                q.push(make_pair(i,j));
                state[i][j] = true;

                while(!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    
                    for(int k = 0; k < 4; k++) {
                        if(x + axis_x[k] < 0 || x + axis_x[k] > N || y + axis_y[k] < 0 || y + axis_y[k] > M) continue;

                        if(arr[x + axis_x[k]][y + axis_y[k]] == 1 && state[x + axis_x[k]][y + axis_y[k]] == false){
                            state[x + axis_x[k]][y + axis_y[k]] = true;
                            q.push(make_pair(x + axis_x[k], y + axis_y[k]));
                        }
                    }
                }
                cnt++;
            }
            
        }
    }
    cout << cnt << endl;
}

void init(int N, int M) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            arr[i][j] = 0;
            state[i][j] = 0;
        }
    }
}

void input() {
    int T;
    int N, M, K;
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> N >> M >> K;
        bfs(N, M, K);
        init(N, M);
    }
}


int main() {
    input();
}