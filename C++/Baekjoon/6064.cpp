#include <iostream>
using namespace std;

int gcd(int m, int n) {
    int a;
    while(n != 0) {
        a = m % n;
        m = n;
        n = a;
    }
    return m;
}

int calender(int M, int N, int x, int y) {
    int k = 1;
    int lcm_num = (M * N) / gcd(M, N);
    
    for(int i = x; i <= lcm_num; i += M) {
        int num = i % N;

        if(num == 0) num = N;
        if(num == y) return i;
    }
    
    return -1;
}


int main() {
    int T;
    cin >> T;

    int M, N, x, y;
    for(int i = 0; i < T; i++) {
        cin >> M >> N >> x >> y;

        cout << calender(M, N, x, y) << endl; 
    }
}