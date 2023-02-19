#include <stdio.h>

int main(){
    int arr[3] = {1,2,3};

    printf("%d %d %d", *arr, *(arr+1), *(arr+2));
    return 0;
}