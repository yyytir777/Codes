#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int n, k;
int weight[MAX];
int value[MAX];
int max_value[101][MAX];

void input() {
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i];
    }
}

void knapsack() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            //i��° ������ ���� �� ���� ��
            if(j >= weight[i]) {
                max_value[i][j] = max(max_value[i-1][j], max_value[i-1][j - weight[i]] + value[i]);
            }
            //i��° ������ ���� �� ���� ��
            else max_value[i][j] = max_value[i-1][j];
        }
    }


    cout << max_value[n][k];
}

int main() {
    input();
    knapsack();
}

