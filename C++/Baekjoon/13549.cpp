#include <iostream>
#include <queue>
using namespace std;

#define MAX 100001

bool visited[MAX] = {0,};
// pair<time, distance> -> pair<int, int>
queue<pair<int, int>> pq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    pq.push(make_pair(0,0));
    visited[0] = 1;

    while (!pq.empty()) {

        int time = pq.front().first;
        int distance = pq.front().second;

        pq.pop();
        visited[distance] = 1;

        if (distance == K) {
            cout << time;
            break;
        }

        // x - 1
        if (distance - 1 >= 0 && visited[distance - 1] == 0) {
            pq.push(make_pair(time + 1, distance - 1));
        }

        // x + 1
        if (distance + 1 <= MAX && visited[distance + 1] == 0) {
            pq.push(make_pair(time + 1, distance + 1));
        }

        // 2x
        if (distance * 2 <= MAX && visited[distance * 2] == 0) {
            pq.push(make_pair(time, distance * 2));
        }
    }
    return 0;
}