#include <iostream>
#include <vector>
#define N 6
#define INF 10000000
using namespace std;

vector<pair<int, int>> graph[N] = {
    {{4,5}, {1,5}, {2,0}, {5,3}, {3,4}},
    {{4,5}, {1,5}, {2,1}, {5,3}, {3,4}},
    {{4,5}, {1,5}, {2,1}, {5,3}, {3,4}},
    {{4,5}, {1,5}, {2,1}, {5,3}, {3,4}},
    {{4,5}, {1,5}, {2,1}, {5,3}, {3,4}},
    {{4,5}, {1,5}, {2,1}, {5,3}, {3,4}},
};

int dist[N];

int main() {
    for(int i = 0; i < N; i++) {
        dist[i] = INF;
    }
}