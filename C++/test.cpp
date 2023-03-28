#include <iostream>
using namespace std;

int main(){
    cout << 1;
    return 0;
}

void mergesort2(int low, int high){
    int mid;
    if(low < high){
        mid = (low + high) / 2;
        mergesort2(low, mid);
        mergesort2(mid + 1, high);
        merge2(low, mid, high);
    }
}

void merge2(int low, int mid, int high){
    int i, j, k;
    
}