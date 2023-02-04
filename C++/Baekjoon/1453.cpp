#include <iostream>
using namespace std;

int main(){
    bool using_computer[101] = {false,};

    int N;
    cin >> N;

    int reject_cnt = 0;

    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        if(using_computer[n] == false){
            using_computer[n] =true;
        }
        else{
            reject_cnt += 1;
        }
    }
    
    cout << reject_cnt;
    return 0;
}