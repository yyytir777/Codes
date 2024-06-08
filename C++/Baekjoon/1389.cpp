#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 5001
#define INF 987654321
using namespace std;

int N, M;

int graph[MAX][MAX] = {0,};
//         <케빈 베이컨 수, 사람번호>
vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}

void floyd_warshall() {
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(graph[i][k] + graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
}

int kevin(int num) {
    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        if(i == num) continue;
        cnt += graph[num][i];
    }
    return cnt;
}

int main() {
    cin >> N >> M;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            graph[i][j] = INF;
        }
    }

    int a, b;
    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    
    floyd_warshall();

    for(int i = 1; i <= N; i++) {
        v.push_back({kevin(i), i});
    }

    sort(v.begin(), v.end(), compare);

    cout << v[0].second;
}