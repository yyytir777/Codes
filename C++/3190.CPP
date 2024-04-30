#include <iostream>
#include <deque>
#define MAX 105
using namespace std;

int N, K;
bool board[MAX][MAX] = {0,};
bool visit[MAX][MAX] = {0,};
deque<pair<int, int>> d;
deque<pair<int, char>> d1;

bool validate(int x, int y) {
    if(x <= 0 || y <= 0 || x > N || y > N) return false;
    else return true;
}

int main(){
    cin >> N;
    cin >> K;

    int row, column;
    for(int i = 0; i < K; i++) {
        cin >> row >> column;
        board[row][column] = true;
    }
    
    int cnt = 0;
    int axis_x[4] = {0, 1, 0, -1};
    int axis_y[4] = {1, 0, -1, 0};
    int direction = 0;

    int x = 1;
    int y = 1;
    visit[1][1] = 1;
    d.push_back(make_pair(1,1));

    int L;
    cin >> L;

    int pos_time;
    char pos_letter;
    for(int i = 0; i < L; i++) {
        cin >> pos_time >> pos_letter;
        d1.push_back(make_pair(pos_time, pos_letter));
    }

    pos_time = d1.front().first;
    pos_letter = d1.front().second;
    d1.pop_front();

    while(true) {
        cnt++;
        int nx = x + axis_x[direction];
        int ny = y + axis_y[direction];

        if(validate(nx, ny) && !visit[nx][ny]) {
            // 사과 먹었을 때
            if(board[nx][ny]) {
                d.push_front(make_pair(nx, ny));
                board[nx][ny] = 0;
                visit[nx][ny] = 1;
            }
            // 사과 못먹었을 때
            else {
                d.push_front(make_pair(nx, ny));
                visit[nx][ny] = 1;
                int temp_x = d.back().first;
                int temp_y = d.back().second;
                visit[temp_x][temp_y] = 0;
                d.pop_back();
            }

            x = nx;
            y = ny;

            if(cnt == pos_time) {
                if(pos_letter == 'D') direction = (direction + 1) % 4;
                else if(pos_letter == 'L') direction = (direction + 3) % 4;

                if(d1.empty()) continue;
                pos_time = d1.front().first;
                pos_letter = d1.front().second;
                d1.pop_front();
            }
        }
        else {
            cout << cnt;
            break;
        }
    }
} 