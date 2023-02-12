#include <iostream>
using namespace std;

#define M 1001

int arr[M];
int dp[M] = {0,};

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int l = 0;

    for(int i = 1; i <= n; i++){
        dp[i] = 1;
        for(int j = )
        if(tmp < arr[i]){
            l++;
            tmp = arr[i];
        }
    }
    cout << l;
    return 0;
}