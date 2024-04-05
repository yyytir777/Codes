#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 26
using namespace std;

int graph[MAX][MAX] = {0,};
bool state[MAX][MAX];
int n;
vector<int> v;
queue<pair<int, int>> q;

int axis_x[4] = {1,-1,0,0};
int axis_y[4] = {0,0,-1,1};

void bfs(int i, int j) {
    int cnt = 0;
    state[i][j] = true;
    q.push(make_pair(i, j));

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        cnt++;

        for(int i = 0; i < 4; i++) {
            if(graph[x + axis_x[i]][y + axis_y[i]] == 1 && state[x + axis_x[i]][y + axis_y[i]] == false) {
                q.push(make_pair(x + axis_x[i], y + axis_y[i]));
                state[x + axis_x[i]][y + axis_y[i]] = true;
            }
        }
    }
    v.push_back(cnt);
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;

        for(int j = 0; j < n; j++) {
            graph[i][j] = temp[j] - 48;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // graph가 1이고 방문하지 않았으면 bfs or dfs
            if(graph[i][j] == 1 && state[i][j] == false) {
                bfs(i, j);
            }
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() << endl;

    vector<int>::iterator iter;
    iter = v.begin();

    for(;iter != v.end(); iter++) {
        cout << *iter << endl;
    }
}