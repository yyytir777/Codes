#include <bits/stdc++.h>
#define MAX 2188
using namespace std;

int graph[MAX][MAX];
int n;
int num_of_minus_one = 0;
int num_of_zero = 0;
int num_of_one = 0;

void recursion(int num, int r, int c) {
    if(num == 1) {
        if(graph[r][c] == -1) {
            num_of_minus_one++;
        }
        else if(graph[r][c] == 0) {
            num_of_zero++;
        }
        else if(graph[r][c] == 1) {
            num_of_one++;
        }
        return;
    }

    bool minus_one_flag = 1, zero_flag = 1, one_flag = 1;

    //one flag
    for(int i = r; i < r + num; i++) {
        for(int j = c; j < c + num; j++) {
            if(graph[i][j] == -1 || graph[i][j] == 0) one_flag = 0; 
        }
    }

    //zero flag
    for(int i = r; i < r + num; i++) {
        for(int j = c; j < c + num; j++) {
            if(graph[i][j] == -1 || graph[i][j] == 1) zero_flag = 0; 
        }
    }

    //minus one flag
    for(int i = r; i < r + num; i++) {
        for(int j = c; j < c + num; j++) {
            if(graph[i][j] == 0 || graph[i][j] == 1) minus_one_flag = 0; 
        }
    }

    if(one_flag || zero_flag || minus_one_flag) {
        if(one_flag) num_of_one++;
        if(zero_flag) num_of_zero++;
        if(minus_one_flag) num_of_minus_one++;
        return;
    }

    int offset = num / 3;
    recursion(offset, r, c);
    recursion(offset, r + offset, c);
    recursion(offset, r + offset * 2, c);
    recursion(offset, r, c + offset);
    recursion(offset, r + offset, c + offset);
    recursion(offset, r + offset * 2, c + offset);
    recursion(offset, r, c + offset * 2);
    recursion(offset, r + offset, c + offset * 2);
    recursion(offset, r + offset * 2, c + offset * 2);
}

int main() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }

    recursion(n, 1, 1);

    cout << num_of_minus_one << '\n' << num_of_zero << '\n' << num_of_one;
}