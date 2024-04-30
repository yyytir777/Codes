#include <iostream>
#include <queue>
using namespace std;


int heapSort(int* heap, int* arr, int n) {

    
}

int main() {
    int heap[] = {4, 7, 2, 6, 9, 1};
    int arr[];
    int n = sizeof(heap) / sizeof(int);

    heapSort(heap, arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}