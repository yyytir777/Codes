#include <bits/stdc++.h>
#include <time.h>
using namespace std;

void swap(int *arr, int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void bubbleSort(int* arr, int n) {
    
    int key, j;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j+1]) swap(arr, j, j + 1);
        }
    }
}


int main() {
    int arr[] = {4, 7, 2, 6, 9, 1};
    int n = sizeof(arr) / sizeof(int);

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}