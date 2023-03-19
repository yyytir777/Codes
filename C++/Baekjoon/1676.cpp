#include <iostream>
using namespace std;

int arr[501];

int main(){
    int n;
    cin >> n;

    int answer = 0;
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        int tmp = i;
        while(true){
            if(tmp % 5 == 0){
                tmp /= 5;
                cnt++;
            }
            else{
                break;
            }
        }
        arr[i] = cnt;
    }

    for(int i = 1; i <= n; i++){
        answer += arr[i];
    }

    cout << answer << '\n';

    return 0;
}