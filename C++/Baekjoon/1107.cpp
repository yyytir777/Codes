#include <iostream>
#include <string>
using namespace std;

bool broken_button[11] = {0,};
int N, M;

int getCount(int num) {
    // 가려는 채널이 0일때
    if(num == 0) {
        if(broken_button[0]) return 0;
        else return 1;
    }

    // 가려는 채널이 1이상일때
    int cnt = 0;
    while(num > 0) {
        if(broken_button[num % 10]) {
            return 0;
        }
        num /= 10;
        cnt++;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin >> M;

    int tmp;  
    for(int i = 0; i < M; i++) {
        cin >> tmp;
        broken_button[tmp] = 1;
    }

    int gap = abs(N - 100);
    for(int i = 0; i <= 1000000; i++) {
        int num = i;
        int result = getCount(num);

        if(result != 0) gap = min(gap, result + abs(N - num));
    }

    cout << gap;
}