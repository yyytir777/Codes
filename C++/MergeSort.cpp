#include <bits/stdc++.h>
using namespace std;

int sorted[6];

void merge(int *arr, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int idx = left;

    //arr -> sorted로의 합병
    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            sorted[idx++] = arr[i++];
        }
        else {
            sorted[idx++] = arr[j++];
        }
    }

    // 남은 arr값 sorted로 이동
    while (i <= mid) {
        sorted[idx++] = arr[i++];
    }
    // 남은 arr값 sorted로 이동
    while (j <= right) {
        sorted[idx++] = arr[j++];
    }

    // 재사용위해 sorted된 값들을 arr로 복사
    for(int k = left; k <= right; k++) {
        arr[k] = sorted[k];
    }
}

void mergeSort(int* arr, int start, int end) {
    int mid;
    if(start < end) {
        mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }


}


int main() {
    int arr[] = {4, 7, 2, 6, 9, 1};
    int n = sizeof(arr) / sizeof(int);

    mergeSort(arr, 0, n-1);

    for (int i = 0; i < n; i++)
    {
        cout << sorted[i] << " ";
    }
}