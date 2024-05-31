#include <bits/stdc++.h>
using namespace std;

// 칸 수, depth
queue<pair<int, int>> q;
map<int, int> ladder;
map<int, int> snake;
bool ladder_mapped[101] = {0,};
bool snake_mapped[101] = {0,};

bool visited[101] = {0,};

int bfs(int start) {
    q.push({start, 0});
    visited[start] = 1;

    while(!q.empty()) {
        pair<int, int> node = q.front();
        q.pop();

        if(node.first == 100) return node.second;

        for(int i = 1; i <= 6; i++) {
            if(node.first + i > 100) continue;

            int nxt_depth = node.second + 1;
            int nxt_level = node.first + i;
            if(!visited[nxt_level]) {

                visited[nxt_level] = 1;

                // 사다리가 있다면
                if (ladder_mapped[nxt_level]) {
                    q.push({ladder[nxt_level], nxt_depth});
                    visited[ladder[nxt_level]] = 1;
                    continue;
                }
                // 뱀이 있다면
                else if (snake_mapped[nxt_level]) {
                    q.push({snake[nxt_level], nxt_depth});
                    visited[snake[nxt_level]] = 1;
                    continue;
                }

                q.push({nxt_level, nxt_depth});
            }


        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int start, end;
    for(int i = 0; i < n; i++) {
        cin >> start >> end;
        ladder.insert({start, end});
        ladder_mapped[start] = 1;
    }
    
    for(int i = 0; i < m; i++) {
        cin >> start >> end;
        snake.insert({start, end});
        snake_mapped[start] = 1;
    }

    cout << bfs(1);
}