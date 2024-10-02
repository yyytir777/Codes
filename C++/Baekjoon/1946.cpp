#include <bits/stdc++.h>
#define MAX 21
using namespace std;

int paper_grade[MAX];
int interview_grade[MAX];

int main() {
    int tc;
    cin >> tc;

    int n;
    while(tc--) {
        cin >> n;

        for(int i = 1; i <= n; i++) {
            cin >> paper_grade[i] >> interview_grade[i];
        }
    }
    return 0;
}