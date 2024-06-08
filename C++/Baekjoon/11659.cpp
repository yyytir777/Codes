#include <iostream>
#define MAX 100001
using namespace std;

int arr[MAX] = {0,};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        if(i > 1) arr[i] += arr[i-1];
    }

    int begin, end;
    for(int i = 0; i < M; i++) {
        int sum = 0;
        cin >> begin >> end;
        cout << arr[end] - arr[begin-1] << '\n';
    }
}