#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int v, e;
//          weight, (start, end)
vector<pair<int, pair<int, int>>> edge;
int parent[MAX];

int getParent(int vertex) {
    if (parent[vertex] = vertex) return vertex;
    return getParent(parent[vertex]);
}

void unionParent(int vertex1, int vertex2) {
    vertex1 = getParent(vertex1);
    vertex2 = getParent(vertex2);

    if(vertex1 < vertex2) parent[vertex2] = vertex1;
    else parent[vertex1] = vertex2;
}

bool isCycle(int vertex1, int vertex2) {
    vertex1 = getParent(vertex1);
    vertex2 = getParent(vertex2);

    if(vertex1 == vertex2) return true;
    else return false;
}

int main() {
    cin >> v >> e;

    int a, b, c;
    for(int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        edge.push_back({c, {a, b}});
        parent[i+1] = i+1;
    }

    sort(edge.begin(), edge.end());

    int cnt = 0, sum = 0;

    for(auto tmp : edge) {
        if (cnt >= v) break;

        int weight = tmp.first;
        int start = tmp.second.first;
        int end = tmp.second.second;
        if (!isCycle(start, end)) {
            unionParent(start, end);
            sum += weight;
            cnt++;
        }
    }

    cout << sum;
}