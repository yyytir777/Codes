#include <bits/stdc++.h>
#include <time.h>
using namespace std;

void swap(int *arr, int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void insertionSort(int* arr, int n) {
    
    int key, j;
    for(int i = 1; i < n; i++) {
        key = arr[i];
        
        j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        
        arr[j+1] = key;
    }
}


int main() {
    int arr[] = {4, 7, 2, 6, 9, 1};
    int n = sizeof(arr) / sizeof(int);

    insertionSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}