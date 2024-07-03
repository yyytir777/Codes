#include <bits/stdc++.h>
#define MAX 6
using namespace std;

long long mul[MAX][MAX];
long long matrix[MAX][MAX];
long long n, b;

void multiply(long long a1[MAX][MAX], long long a2[MAX][MAX]) {
    long long copy[MAX][MAX];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            copy[i][j] = 0;
            for(int k = 0; k < n; k++) copy[i][j] += a1[i][k] * a2[k][j];
            copy[i][j] %= 1000;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            a1[i][j] = copy[i][j];
        }
    }
}

int main() {
    cin >> n >> b;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mul[i][j];
        }
        matrix[i][i] = 1;
    }

    while(b > 0) {
        if(b % 2 == 1) {
            multiply(matrix, mul);
            b -= 1;
        }
        else {
            multiply(mul, mul);
            b /= 2;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << '\n';
    }
}