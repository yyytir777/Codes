#include <iostream>
using namespace std;

#define MAX 1000001

long long node[MAX];
// i : index, x : ������ ��, n : ������ ��ġ, s : start, e : end
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

        // b��° ���� c�� ����
        if (a == 1) {
            update(1, 0, N, b-1, )
        }

        // b��° ������ c��° �������� ��
        else if (a == 2) {

        }
    }
    return 0;
}