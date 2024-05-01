#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define BLANK 0
#define WALL 1
#define VIRUS 2
#define MAX 10
using namespace std;

int N, M;
int map[MAX][MAX];
int map_copy[MAX][MAX];
bool visited[MAX][MAX] = {false,};
int axis_i[4] = {1,-1,0,0};
int axis_j[4] = {0,0,-1,1};
vector<pair<int, int>> virus_v; //바이러스의 위치 이볅
vector<int> blank_v; // 빈칸의 개수 입력 -> 최댓값 위해
queue<pair<int, int>> bfs_q; //bfs에서 사용되는 큐

void init() {
    for(int i = 0 ; i < N; i++) {
        for(int j = 0; j < M; j++) {
            map_copy[i][j] = map[i][j];
        }
    }

    while(!bfs_q.empty()) bfs_q.pop();
}

void bfs() {
    for(auto tmp : virus_v) {
        bfs_q.push({tmp.first, tmp.second});
    }

    while(!bfs_q.empty()) {
        int x = bfs_q.front().first;
        int y = bfs_q.front().second;
        bfs_q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + axis_i[i];
            int ny = y + axis_j[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            if(map_copy[nx][ny] == BLANK) {
                map_copy[nx][ny] = VIRUS;
                bfs_q.push({nx, ny});
            }
        }
    }

    // 개수 세서 vector에 저장
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(map_copy[i][j] == BLANK) cnt++;

            if(map_copy[i][j] == VIRUS && map[i][j] != VIRUS) map_copy[i][j] = BLANK;
        }
    }
    blank_v.push_back(cnt);
    
    return;
}

void make_wall(int n) {
    if(n == 3) {
        // cout << endl;
        // for(int i = 0; i < N; i++) {
        //     for(int j = 0; j < M; j++) {
        //         cout << map_copy[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        bfs();
        return;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(map_copy[i][j] == BLANK) {
                map_copy[i][j] = WALL;
                make_wall(n+1);
                map_copy[i][j] = BLANK;
            }
        }
    }
}

int main() {
    cin >> N >> M;

    int tmp;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> tmp;
            map[i][j] = tmp;
            if(tmp == VIRUS) virus_v.push_back({i, j});
        }
    }

    // 벽 3개를 브루트포스로 생성 => ??
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(map[i][j] == BLANK) {
                init();
                map_copy[i][j] = WALL;
                make_wall(1);
                map_copy[i][j] = BLANK;
            }
        }
    }

    sort(blank_v.begin(), blank_v.end());

    // for(auto tmp : blank_v) {
    //     cout << tmp << " ";
    // }
    cout << blank_v[blank_v.size() - 1];
    return 0;
}