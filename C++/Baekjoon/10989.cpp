#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int arr[10001] = {0}; 
    /*최대 10,000,000개의 정수를 입력받지만 
    정수의 크기가 10,000으로 정해져 있으므로
    배열의 크기를 10,000을 설정하고 각 배열의
    인덱스에 개수를 추가 */

    for(int i = 0; i < n; i++){
        int cnt;
        cin >> cnt;
        arr[cnt] += 1;
    }

    for(int i = 0; i <= 10000; i++){
        for(int j = 0; j < arr[i]; j++){
            cout << i << "\n";
        }
    }
}