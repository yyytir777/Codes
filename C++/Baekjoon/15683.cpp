#include <bits/stdc++.h>
#define MAX 9
#define BLANK 0
#define WALL 6
using namespace std;
typedef pair<int, int> Pair;

int n, m;
int room[MAX][MAX];

vector<Pair> wallPositions;
vector<Pair> cctvPositions;

vector<int> minBlindCandidates;

void print() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << room[i][j] << " ";
        }
        cout << '\n';
    }
}

void input() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> room[i][j];
            if(room[i][j] != BLANK) {
                if(room[i][j] == WALL) wallPositions.push_back({i,j});
                else cctvPositions.push_back({i,j});
            }
        }
    }
}

void dfs(int index) {
    if(index == cctvPositions.size()) {
        int blind = calculateBlind();
        minBlindCandidates
    }

    for(int i = 0;  < cctvPositions.size(); i++) {
        if(/*n번 cctv일 경우*/) {
            for( /*방향 전환*/) {

                dfs(i + 1);
            }
        }
    }
}

void solve() {

    dfs();

    sort(minBlindCandidates.begin(), minBlindCandidates.end());
    cout << minBlindCandidates[0];
}

int main() {
    input();
    // solve();
    print();
}