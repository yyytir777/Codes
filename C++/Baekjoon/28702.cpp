#include <bits/stdc++.h>
using namespace std;

int main() {
    string n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    int result_num;
    if('1' <= n1[0] && n1[0] <= '9') result_num = stoi(n1) + 3;
    else if('1' <= n2[0] && n2[0] <= '9') result_num = stoi(n2) + 2;
    else if('1' <= n3[0] && n3[0] <= '9') result_num = stoi(n3) + 1;

    if(result_num % 3 == 0) {
        if(result_num % 5 == 0) cout << "FizzBuzz";
        else cout << "Fizz";
    }
    else {
        if(result_num % 5 == 0) cout << "Buzz";
        else cout << result_num;
    }
}