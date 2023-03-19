#include <iostream>
using namespace std;

int arr[101] = {0,};

int main(){
    ios::sync_with_stdio(false);
    tie.cin(NULL);
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int sum;
    int answer = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                sum = arr[i] + arr[j] + arr[k];
                if(sum <= m && sum > answer){
                    answer = sum;
                }
            }
        }
    }
    cout << answer << '\n';
    return 0;
}