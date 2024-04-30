#include <bits/stdc++.h>
using namespace std;

void swap(int *arr, int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

int partition(int *arr, int left, int right) {
    int low = left + 1;
    int high = right;

    int pivot = arr[left];

    while(low < high) {
        while(low <= right && arr[low] < pivot) low++;
        while(high >= left && arr[high] > pivot) high--;

        if(low <= high) {
            swap(arr, low, high);
        }
    }

    swap(arr, left, high);

    return high;
}

void quickSort(int* arr, int start, int end) {
    if(start < end) {
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot-1);
        quickSort(arr, pivot+1, end);
    }
}


int main() {
    int arr[] = {4, 7, 2, 6, 9, 1};
    int n = sizeof(arr) / sizeof(int);

    quickSort(arr, 0, n-1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}