#include <bits/stdc++.h>
#define MAX 100001
using namespace std;
//  value, left, right
pair<int, pair<int, int>> graph[MAX];
bool visited[MAX] = {0,};
int parents[MAX];
int n;

int main() {
    cin >> n;

    int a, b, c;
    for(int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        graph[a] = {a, {b, c}};
    }

    int end_node, tmp = 1;
    while(tmp != -1) {
        end_node = tmp;
        tmp = graph[tmp].second.second;
    }

    int cnt = 0;
    int cur_node = 1;
    visited[cur_node] = 1;
    while(cur_node != -1) {
        if (graph[cur_node].second.first != -1 && !visited[graph[cur_node].second.first]) {
            visited[graph[cur_node].second.first] = 1;
            parents[graph[cur_node].second.first] = cur_node; //부모 노드 기록 (graph[cur_node].second.first의 parent는 cur_node이다)
            cur_node = graph[cur_node].second.first;
            cnt++;
        }
        else if (graph[cur_node].second.second != -1 && !visited[graph[cur_node].second.second]) {
            visited[graph[cur_node].second.second] = 1;
            parents[graph[cur_node].second.second] = cur_node; //부모 노드 기록 (graph[cur_node].second.second의 parent는 cur_node이다)
            cur_node = graph[cur_node].second.second;
            cnt++;
        }
        else if (cur_node == end_node) {
            break;
        }
        else if (graph[parents[cur_node]].second.first == cur_node || graph[parents[cur_node]].second.second == cur_node) {
            cur_node = parents[cur_node];
            cnt++;
        }
    }
    cout << cnt;
}