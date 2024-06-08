#include <iostream>
#define MAX 10001
using namespace std;

int arr[MAX];

void post(int start, int end) {
    if(start >= end) return;
    
    int i;
    for(i = start + 1; i < end; i++) {
        if(arr[start] < arr[i]) break;
    }

    post(start + 1, i);
    post(i, end);
    cout << arr[start] << '\n';
}

int main() {
    int tmp;
    int idx = 0;
    while(cin >> tmp) {
            arr[idx++] = tmp;
            tmp = 0;
    }

    post(0, idx);

    return 0;
}