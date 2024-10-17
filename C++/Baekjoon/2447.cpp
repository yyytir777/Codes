#include <bits/stdc++.h>
#define MAX 6562
using namespace std;

bool graph[MAX][MAX] = {0,};
int n;

void printSquare() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(graph[i][j] == 0) cout << " ";
            else cout << "*";
        }
        cout << '\n';
    }
}

void recursion(int num, int row, int col) {
    if(num == 3) {
        for(int i = row; i <= row + 2; i++) {
            for(int j = col; j <= col + 2; j++) {
                if(i == (row + 1) && j == (col + 1)) graph[i][j] = 0;
                else graph[i][j] = 1;
            }
        }
        return;
    }
    
    int offset = num / 3;
    recursion(offset, row, col);
    recursion(offset, row + offset, col);
    recursion(offset, row + offset * 2, col);

    recursion(offset, row, col + offset);
    recursion(offset, row + offset * 2, col + offset);

    recursion(offset, row, col + offset * 2);
    recursion(offset, row + offset, col + offset * 2);
    recursion(offset, row + offset * 2, col + offset * 2);
}

int main() {
    cin >> n;
    recursion(n, 1, 1);
    printSquare();
    return 0;
}