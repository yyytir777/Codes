#include <iostream>
#include <queue>
#define INF 100000000
#define MAX 125
using namespace std;

 //                 {{row, col}, cost}
priority_queue<pair<pair<int, int>, int>> pq;
int arr[MAX][MAX];
int cost[MAX][MAX];

int row_axis[4] = {0, 0, -1, 1};
int col_axis[4] = {1, -1, 0, 0};
int N;

void dijkstra(int x, int y) {
    pq.push({{x, y}, -arr[x][y]});
    cost[x][y] = arr[x][y];

    while(!pq.empty()) {
        pair<int, int> cur_node = pq.top().first;
        int cur_cost = -pq.top().second;
        pq.pop();

        if(cost[cur_node.first][cur_node.second] < cur_cost) continue;

        for(int i = 0; i < 4; i++) {
            int dx = cur_node.first + row_axis[i];
            int dy = cur_node.second + col_axis[i];

            if(dx < 0 || dy < 0 || dx >= N || dy >= N) continue;
            
            pair<int, int> nxt_node = {dx, dy};
            int nxt_cost = cost[cur_node.first][cur_node.second] + arr[dx][dy];

            if(cost[dx][dy] > nxt_cost) {
                cost[dx][dy] = nxt_cost;
                pq.push({nxt_node, -nxt_cost});
            }
        }
    }
}

int main() {

    int idx = 1;
    while(true) {
        cin >> N;

        if(!N) return 0;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> arr[i][j];
                cost[i][j] = INF;
            }
        }

        dijkstra(0, 0);

        printf("Problem %d: %d\n", idx++, cost[N-1][N-1]);
    }
}
