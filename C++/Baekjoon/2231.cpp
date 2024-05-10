#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main() {
    int N;
    cin >> N;

    for(int i = 1; i < N; i++) {
        int num = i;
        int sum = i;
        while(num != 0) {
            sum += num % 10;
            num /= 10;
        }

        if(sum == N) {
            cout << i;
            return 0;
        }
    }
    cout << "0";
}