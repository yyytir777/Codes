#include <iostream>
#include <queue>
using namespace std;

queue<int> q[10];

int getDigits(int num, int digit) {
    while(digit) {
        num /= 10;
        digit--;
    }

    return num;
}

void radixSort(int* arr, int n) {
    int digits = 2;
    for(int i = 0; i < digits; i++) {

        for(int j = 0; j < n; j++) {
            int num = getDigits(arr[j], i);
            q[num].push(arr[j]);
        }

        int idx = 0;
        for(int j = 0; j < 10; j++) {

            while(!q[j].empty()) {
                arr[idx] = q[j].back();
                q[j].pop();
                idx++;
            }
        }
    }
}

int main() {
    int arr[] = {41, 74, 23, 61, 98, 13};
    int n = sizeof(arr) / sizeof(int);

    radixSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}