#include <bits/stdc++.h>
#define MAX 51
#define BLANK 0
#define HOME 1
#define CHICKEN 2
using namespace std;

typedef pair<int, int> Pair;

int n, m;
int city[MAX][MAX];
vector<Pair> home_pos;
vector<Pair> chicken_pos;
vector<int> minDistanceOfHomePos;


void input() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> city[i][j];

            if(city[i][j] == HOME) home_pos.push_back({i,j});
            else if(city[i][j] == CHICKEN) chicken_pos.push_back({i,j});
        }
    }
}

int getDistance(Pair chicken, Pair home) {
    int x = abs(chicken.first - home.first);
    int y = abs(chicken.second - home.second);
    return x+y;
}

void dfs(vector<Pair>& picked_chicken, int index, int cnt) {
    if(cnt == m) {
        int sum_distance = 0;
        for(Pair homePos : home_pos) {
            vector<int> distanceOfChicken;
            for(Pair chickenPos : picked_chicken) {
                int distance = getDistance(chickenPos, homePos);
                distanceOfChicken.push_back(distance);
            }
            sort(distanceOfChicken.begin(), distanceOfChicken.end());
            sum_distance += distanceOfChicken[0];
        }
        minDistanceOfHomePos.push_back(sum_distance);
        return;
    }

    for(int i = index; i < chicken_pos.size(); i++) {
        picked_chicken.push_back(chicken_pos[i]);
        dfs(picked_chicken, i + 1, cnt + 1);
        picked_chicken.pop_back();
    }
}

void solve() {
    vector<Pair> picked_chicken;
    dfs(picked_chicken, 0, 0);

    sort(minDistanceOfHomePos.begin(), minDistanceOfHomePos.end());
    cout << minDistanceOfHomePos[0];
}

int main() {
    input();
    solve();
}