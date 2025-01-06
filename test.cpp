// 1939 cpp -> 다시 풀기 = dfs가 아닌 이분탐색으로 풀어야함
// 
#include <bits/stdc++.h>
#define MAX 10001
#define INF 110000000
#define ll long long
using namespace std;

const long long long_max = LLONG_MAX;

int n, m;
int graph[MAX][MAX];
int depart, dest;
bool visited[MAX][MAX] = {0,};
vector<int> min_weight_candidate;
stack<pair<int, int>> s; // node, min_dist;

void init_graph() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            graph[i][j] = INF;
        }
    }
}

void print_graph() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << '\n';
    }
}

void input() {
    cin >> n >> m;
    init_graph();
    int a, b;
    int c;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if(c < graph[a][b]) {
            graph[a][b] = c;
            graph[b][a] = c;
        }
    }

    cin >> depart >> dest;
}

void dfs(int node, int min_weight) {

    if(node == dest) {
        min_weight_candidate.push_back(min_weight);
        return;
    }

    for(int i = 1; i <= n; i++) {
        if(i == node || graph[node][i] == long_max) continue;

        int temp;
        if(!visited[node][i]) {
            temp = min_weight;
            min_weight = min(min_weight, graph[node][i]);
            visited[node][i] = 1;
            visited[i][node] = 1;
            dfs(i, min_weight);
            visited[node][i] = 0;
            visited[i][node] = 0;
        }

        min_weight = temp;
    }
    return;
}

// void dfsv2(int depart) {
//     s.push({depart, long_max});

//     while(!s.empty()) {
//         int node = s.front().first;
//         int min_weight = s.front().second;
//         s.pop();

        
//         for(int i = 1; i <= n; i++) {

//         }
//     }
// }

bool compare(ll a, ll b) {
    return a > b;
}

void solve() {
    dfs(depart, INF);

    sort(min_weight_candidate.begin(), min_weight_candidate.end(), compare);

    cout << min_weight_candidate[0];
}

int main() {
    input();
    solve();
    return 0;
}