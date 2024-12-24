#include <bits/stdc++.h>
#define MAX 11
#define N 1
#define S -1
#define W 2
#define E -2
using namespace std;

typedef pair<int, int> Pair;

int n, m;
char graph[MAX][MAX];
int direction[4] = {N, S, W, E};
pair<int, int> red, blue, hole;
vector<pair<int, int>> pos;
queue<pair<vector<pair<int, int>>, int>> q;

void input() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> graph[i][j];

            if(graph[i][j] == 'R') red = {i,j};
            else if(graph[i][j] == 'B') blue = {i,j};
            else if(graph[i][j] == 'O') hole = {i,j};
        }
    }
    pos.push_back(red);
    pos.push_back(blue);
}

void print() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << graph[i][j] << " ";
        }
        cout << '\n';
    }
}

Pair getAxis(int dir) {
    int r, c;
    if(dir == N) r = -1, c = 0;
    else if(dir == S) r = 1, c = 0;
    else if(dir == W) r = 0, c = -1;
    else if(dir == E) r = 0, c = 1;

    Pair ans = {r, c};
    return ans;
}

/*
blue가 먼저 구멍에 빠지면 false,
red가 먼저 구멍에 빠지면 true 반환
아무것도 빠지지 않으면 q에 push

B구슬을 먼저 이동시키고 R구슬을 이동시켜야함
*/
bool move(int dir, vector<Pair> pos, int cur_cnt) {

    Pair red = pos[0];
    Pair blue = pos[1];
    Pair cur_red = red;
    Pair cur_blue = blue;

    Pair movePos = getAxis(dir);
    int r = movePos.first;
    int c = movePos.second;

    while(true) {
        // 벽 혹은 R구슬을 만났을 때
        if(graph[blue.first + r][blue.second + c] == '#' || graph[blue.first + r][blue.second + c] == 'R')
            break;
        // 길을 만났을 때
        else if(graph[blue.first + r][blue.second + c] == '.') {
            blue = {blue.first + r, blue.second + c};
        }
        // 구멍을 만났을 때
        else if(graph[blue.first + r][blue.second + c] == 'O') return false;
    }

    while(true) {
        // 벽 혹은 B구슬을 만났을 때
        if(graph[red.first + r][red.second + c] == '#' || graph[red.first + r][red.second + c] == 'B')
            break;
        // 길을 만났을 때
        else if(graph[red.first + r][red.second + c] == '.') {
            red = {red.first + r, red.second + c};
        }
        // 구멍을 만났을 때
        else if(graph[red.first + r][red.second + c] == 'O')
            return true;
    }

    // 좌표 변환이 없으면 push없이 리턴
    if(cur_blue == blue && cur_red == red) return false;

    vector<pair<int, int>> nxt_pos = {red, blue};
    q.push({nxt_pos, cur_cnt + 1});
    return false;
}

void bfs(vector<pair<int, int>> start, int cnt) {
    q.push({start, 0});

    while(!q.empty()) {
        vector<pair<int, int>> cur_pos = q.front().first;
        int cur_cnt = q.front().second;
        q.pop();

        if(cur_cnt > 10) {
            cout << "-1";
            return;
        }

        for(int i = 0; i < 4; i++) {
            bool isRedOut = move(direction[i], cur_pos, cur_cnt);
            if(isRedOut) {
                cout << cur_cnt + 1;
                return;
            }
        }
    }
}

void solve(){
    bfs(pos, 0);
}

int main() {
    input();
    solve();
    // debug();
}