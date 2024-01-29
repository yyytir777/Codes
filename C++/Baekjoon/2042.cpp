#include <iostream>
using namespace std;

#define MAX 1000001

long long node[MAX];
// i : index, x : 변경할 값, n : 변경할 위치, s : start, e : end
void update(int i, int x, int n, int s, int e) {
    if (i < s || e < i) node[n];
    if (i <= s && e <= i)
    
}
int main(){
    
    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        cin >> node[i];
    }


    int a, b, c;
    for (int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;

        // b번째 수를 c로 변경
        if (a == 1) {
            update(1, 0, N, b-1, )
        }

        // b번째 수부터 c번째 수까지의 합
        else if (a == 2) {

        }
    }
    return 0;
}