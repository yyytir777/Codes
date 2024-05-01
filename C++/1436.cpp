#include <iostream>
using namespace std;


int main() {
    int N;
    cin >> N;

    int num = 666;
    int cnt = 0;
    string num_str;
    while(true) {
        num_str = to_string(num);

        for(int i = num_str.length() - 3; i >= 0 ; i--) {
            if(num_str[i] == '6' && num_str[i+1] == '6' && num_str[i+2] == '6') {
                cnt++;
                if(cnt == N) {
                    cout << num_str;
                    return 0;
                }
                break;
            }
        }
        num++;
        num_str = to_string(num);
    }
}