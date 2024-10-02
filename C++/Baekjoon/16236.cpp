#include <bits/stdc++.h>
#define MAX 21
#define Blank 0
#define Shark 9
using namespace std;

int space[MAX][MAX];
int n;

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> space[i][j];
        }
    }
}