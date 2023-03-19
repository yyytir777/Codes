#include <iostream>
using namespace std;

bool check[1000001] = {1,};

int main(){
    int min, max;
    cin >> min >> max;

    for(int i = 2; i * i <= max; i++){
        int cnt = 1;
        while((i * i) <= max){
            check[i * i * cnt] = 0; 
            cnt++;
        }
    }

    int answer = 0;
    for(int i = min - 1; i < max; i++){
        if(check[i] == 1){
            answer++;
        }
    }
    cout << answer << '\n';
    
    return 0;
}