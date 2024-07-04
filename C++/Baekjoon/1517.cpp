#include <bits/stdc++.h>
#define MAX 500001
using namespace std;

int n;
long long cnt = 0;
int arr[MAX];
int tmp[MAX];

void merge(int *v, int start, int mid, int end) {
    int idx = start;
    int left = start;
    int right = mid + 1;

    while(left <= mid && right <= end) {
        if(v[left] <= v[right]) {
            tmp[idx++] = v[left++];
        }
        else {
            cnt += right - idx;
            tmp[idx++] = v[right++];
        }
    }

    if(left <= mid) { //왼쪽 배열이 남았을 때
        for(int i = left; i <= mid; i++) {
            tmp[idx++] = v[i];
        }
    }
    else {
        for(int i = right; i <= end; i++) {
            tmp[idx++] = v[i];
        }
    }

    for(int i = start; i <= end; i++) {
        v[i] = tmp[i];
    }
}

void mergeSort(int *arr1, int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;
        mergeSort(arr1, start, mid);
        mergeSort(arr1, mid + 1, end);
        merge(arr1, start, mid, end);
    }
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    cout << cnt;
}