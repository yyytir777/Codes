#include <iostream>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m, n;
    cin >> m >> n;

    for(int i = m; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= i; j++){
            if(i % j == 0){ //나누어지면
                cnt++;
            }
        }
        if(cnt == 2){
            cout << i << '\n';
        }
    }
    return 0;
}