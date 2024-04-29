#include <bits/stdc++.h>
using namespace std;

void swap(int *arr, int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void selectionSort(int* arr, int n) {
    
    int min;
    for(int i = 0; i < n; i++) {
        min = i;

        for(int j = i + 1; j < n; j++) {
            min = arr[min] > arr[j] ? j : min;
        }

        if(i != min) swap(arr, i, min);
    }
}


int main() {

    int arr[] = {4, 7, 2, 6, 9, 1};
    int n = sizeof(arr) / sizeof(int);


    selectionSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}