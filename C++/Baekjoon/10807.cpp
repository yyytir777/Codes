#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int * arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int find_num;
    cin >> find_num;

    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(find_num == arr[i]){
            cnt++;
        }
    }
    cout <<cnt;
    return 0;
}