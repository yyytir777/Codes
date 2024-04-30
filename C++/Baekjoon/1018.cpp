#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 51
using namespace std;

char board[MAX][MAX] = {0,};
vector<int> v;

string black_board[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

string white_board[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
};

int white(int x, int y) {
    int cnt = 0;

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++){
            if(white_board[i][j] == board[x+i][y+j]) cnt++;
        }
    }
    return cnt;
}

int black(int x , int y) {
    int cnt = 0;

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++){
            if(black_board[i][j] == board[x+i][y+j]) cnt++;
        }
    }
    return cnt;
}

int main() {
    int M, N;
    cin >> M >> N;

    string temp;
    for(int i = 0; i < M; i++) {
        cin >> temp;
        for(int j = 0; j < N; j++) {
            board[i][j] = temp[j];
        }
    }

    for(int i = 0; i + 8 <= M; i++) {
        for(int j = 0; j + 8 <= N; j++) {
            int tmp = min(white(i, j), black(i, j));
            v.push_back(tmp);
        }
    }

    sort(v.begin(), v.end());

    cout << v.at(0);
}