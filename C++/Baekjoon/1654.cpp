#include <iostream>
#include <algorithm>
using namespace std;

int LAN[10000] = {0,};
long long answer = 0;
int main(){
    long long k, n; //k = 가지고있는 랜선의 개수, n = 필요한 랜선의 개수
    cin >> k >> n;

    for(int i = 0; i < k; i++){
        cin >> LAN[i];
    }

    sort(LAN, LAN + k);

    long long min = 1;
    long long max = LAN[k-1];

    while(min <= max){
        long long mid = (max + min) / 2;        
        long long length = 0;

        for(int i = 0; i < k; i++){
            length += LAN[i] / mid;
        }

        if(length >= n){
            min = mid + 1;
            if(answer < mid){
                answer = mid;
            }
        }
        else{
            max = mid - 1;
        }
    }

    cout << answer << '\n';
    return 0;
} 