#include <iostream>
#define MAX 1001
using namespace std;

int dp[MAX][MAX] = {0,};

int main() {
    string input1, input2;
    cin >> input1;
    cin >> input2;

    for(int i = 1; i <= input1.length(); i++) {
        for(int j = 1; j <= input2.length(); j++) {
            if(input1[i-1] == input2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
            }
        }
    }

    cout << dp[input1.length()][input2.length()] << '\n';
}