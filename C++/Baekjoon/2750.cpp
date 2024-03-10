#include <iostream>
#include <algorithm> //sort??¡§???
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    

    int cnt;
    cin >> cnt;
    int arr[1000];

    for(int i = 0; i < cnt; i++){
        cin >> arr[i];
    }
    cout << '\n';
    sort(arr, arr + cnt);

    for(int i = 0; i < cnt; i++){
        cout << arr[i] << '\n';
    }
    return 0;
}