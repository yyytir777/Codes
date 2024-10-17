#include <bits/stdc++.h>
#define MAX 65
using namespace std;

vector<char> buffer;

char graph[MAX][MAX];
int n;

//먼저 모두 white or black이면 더 이상 진행 X
//만약 아니라면, "(", ")"괄호 넣고 다음 conquer진행
void recursion(int num, int row, int col) {
    if(num == 1) {
        buffer.push_back(graph[row][col]);
        return;
    }

    bool black_flag = 1;
    for(int i = row; i < row + num; i++) {
        for(int j = col; j < col + num; j++) {
            if(graph[i][j] == '0') black_flag = 0;
        }
    }

    bool white_flag = 1;
    for(int i = row; i < row + num; i++) {
        for(int j = col; j < col + num; j++) {
            if(graph[i][j] == '1') white_flag = 0;
        }
    }

    if(white_flag || black_flag) {
        if(white_flag) buffer.push_back('0');
        if(black_flag) buffer.push_back('1');
        return;
    }

    buffer.push_back('(');

    int offset = num / 2;
    recursion(offset, row, col);
    recursion(offset, row, col + offset);
    recursion(offset, row + offset, col);
    recursion(offset, row + offset, col + offset);

    buffer.push_back(')');
}

int main() {
    cin >> n;

    string tmp;
    for(int i = 1; i <= n; i++) {
        cin >> tmp;
        for(int j = 1; j <= n; j++) {
            graph[i][j] = tmp[j-1];
        }
    }

    recursion(n, 1, 1);

    for(char letter : buffer) cout << letter;

    return 0;
}