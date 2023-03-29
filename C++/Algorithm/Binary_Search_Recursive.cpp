#include <iostream>
using namespace std;

int S[10] = {0,1,2,3,4,5,6,7,8,9};
int x;
int location(int low, int high){
    int mid;
    if(low > high) return 0;
    else{
        mid = (low + high) / 2;
        if(x == S[mid]){
            return mid;
        }
        else if(x < S[mid]){
            return location(low, mid - 1);
        }
        else{ //x > S[mid]
            return location(mid + 1, high);
        }
    }
}

int main(){
    cin >> x;
    cout << location(0, 9);

    return 0;
}