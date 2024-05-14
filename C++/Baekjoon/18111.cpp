#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 500
using namespace std;

int N, M, B;
int grid[MAX][MAX] = {0,};

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main() {
    cin >> N >> M >> B;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    // v : {time: i}
    vector<pair<int, int>> v;
    for(int height = 0; height <= 256; height++) {
        int remove = 0;
        int build = 0;
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                //쌓아야 함
                if(grid[i][j] < height) {
                    cnt = height - grid[i][j];
                    build += cnt;
                }
                //파야 함
                else if(grid[i][j] > height) {
                    cnt = grid[i][j] - height;
                    remove += cnt;
                }
            }
        }

        int time;
        if(remove + B >= build) time = remove * 2 + build;
        else time = -1;

        if(time == -1) continue;
        v.push_back({time, height});
    }

    sort(v.begin(), v.end(), compare);

    cout << v.front().first << " " << v.front().second << endl;
    return 0;
}