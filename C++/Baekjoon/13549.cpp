#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
#define INF 987654321

//                 arrTime, dist
priority_queue<pair<int, int>> pq;
int arrTime[MAX];
int N, K;

int dijkstra(int start) {
    pq.push({0,start});
    arrTime[start] = 0;

    while (!pq.empty()) {
        int cur_time = -pq.top().first;
        int cur_distance = pq.top().second;
        pq.pop();
        
        if (cur_distance == K) return cur_time;

        // x - 1
        if (cur_distance - 1 >= 0 && arrTime[cur_distance - 1] > (cur_time + 1)) {
            arrTime[cur_distance - 1] = cur_time + 1;
            pq.push({-(cur_time + 1), cur_distance - 1});
        }

        // x + 1
        if (cur_distance + 1 < MAX && arrTime[cur_distance + 1] > (cur_time + 1)) {
            pq.push({-(cur_time + 1), cur_distance + 1});
        }

        // 2x
        if (cur_distance * 2 < MAX && arrTime[cur_distance * 2] > cur_time) {
            pq.push({-cur_time, cur_distance * 2});
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    for(int i = 0; i < MAX; i++) {
        arrTime[i] = INF;
    }
    cout << dijkstra(N);
}