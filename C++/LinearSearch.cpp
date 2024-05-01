#include <bits/stdc++.h>
using namespace std;


int linearSearch(int* arr, int num, int n) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == num) return i;
    }
}

int binarySearch(int*arr, int num, int n) {
    int left = 0;
    int right = n - 1;

    while(left <= right) {
        int mid = (left + right) / 2;

        if(arr[mid] == num) return mid;

        else if(arr[mid] > num) right = mid - 1;

        else if(arr[mid] < num) left = mid + 1;
    }

    return -1;
}


int main() {
    int arr[10] = {12, 19, 20, 23, 38, 45, 59, 71, 93, 94};
    int n = sizeof(arr) / sizeof(int);
    int num = 59;
    
    int index = binarySearch(arr, num, n);

    cout << index << endl;
}