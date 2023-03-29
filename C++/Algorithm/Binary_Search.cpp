#include <iostream>
using namespace std;

int binary_search(int n, int *S, int x){
    int low, high, mid;
    low = 1, high = n;
    int location = 0;
    while(low <= high && location == 0){
        mid = (low + high) / 2;
        if(x == S[mid]){
            location = mid;
            return location;
        }
        else if(x < S[mid]){
            high = mid - 1;
        }
        else{ //(x > S[mid])
            low = mid + 1;
        }
    }
    return location;
}

int main(){
    int S[7] = {1,3,7,10,34,68,95};
    cout << binary_search(7, S, 95);
    return 0;
}