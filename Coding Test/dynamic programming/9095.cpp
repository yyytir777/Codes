#include <iostream>
using namespace std;

int dp[12] = {0,};

int main() {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    int T;
    cin >> T;

    int tmp;
    for(int i = 0; i < T; i++) {
        cin >> tmp;

        for(int j = 4; j <= tmp; j++) {
            dp[j] = dp[j-1] + dp[j-2] + dp[j-3];
        }
        cout << dp[tmp] << endl;
    }
}