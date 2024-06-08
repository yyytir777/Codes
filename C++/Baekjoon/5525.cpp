#include <iostream>
#define MAX 1000001
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    string tmp;
    cin >> tmp;

    int cnt = 0;
    for(int i = 0; i < M; i++) {
        int part_cnt = 0;
        if(tmp[i] == 'I') {
            while(tmp[i+1] == 'O' && tmp[i+2] == 'I') {
                part_cnt++;
                if(part_cnt == N) {
                    part_cnt--;
                    cnt++;
                }
                i += 2;
            }
            part_cnt = 0;
        }
    }

    cout << cnt;
}