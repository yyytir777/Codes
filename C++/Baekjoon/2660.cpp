// 2660 cpp
#include <bits/stdc++.h>
#define MAX 52
#define INF 987654321
using namespace std;

int n;
int friends[MAX][MAX];

void init_friends() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            friends[i][j] = INF;
        }
    }
}

void print_friends() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            printf("%d ", friends[i][j]);
        }
        cout << '\n';
    }
}

void input() {
    cin >> n;

    init_friends();

    int a, b;
    while(true) {
        cin >> a >> b;
        if(a == -1 && b == -1) break;
        friends[a][b] = 1;
        friends[b][a] = 1;
    }

}

void floyd_warshall() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            for(int k = 1; k <= n; k++) {
                if(friends[i][j] > friends[i][k] + friends[k][j]) {
                    friends[i][j] = friends[i][k] + friends[k][j];
                    friends[j][i] = friends[i][k] + friends[k][j];
                }
            }
        }
    }
}

void print_grade(vector<pair<int, int>> v) {
    printf("\n");
    for(auto element : v) {
        printf("%d %d\n", element.first, element.second);
    }
    printf("\n");
}

void solve() {
    floyd_warshall();


    vector<pair<int, int>> grade_per_student;
    for(int i = 1; i <= n; i++) {
        int max_grade = 0;
        for(int j = 1; j <= n; j++) {
            if(friends[i][j] == INF) continue;
            if(i == j) continue;
            max_grade = max(max_grade, friends[i][j]);
        }
        grade_per_student.push_back({max_grade, i});
    }

    sort(grade_per_student.begin(), grade_per_student.end());

    int chief_grade = grade_per_student[0].first;
    vector<int> chief_vector;

    for(auto grade : grade_per_student) {
        if(grade.first == chief_grade) {
            chief_vector.push_back(grade.second);
        }
    }

    printf("%d %d\n", chief_grade, chief_vector.size());

    sort(chief_vector.begin(), chief_vector.end());
    for(int candidate : chief_vector) {
        printf("%d ", candidate);
    }
}

int main() {
    input();
    solve();
    return 0;
}