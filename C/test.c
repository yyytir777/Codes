#include <stdio.h>

void MaxAndMix(int **MaxPtr, int **MinPtr, int *arr){
    int *max, *min;

    max = min = &arr[0];
    for(int i = 0; i < 5; i++){
        if(*max < arr[i]){
            max = &arr[i];
        }
        else if(*min > arr[i]){
            min = &arr[i];
        }
    }

    *MaxPtr = max;
    *MinPtr = min;
}

int main(){
    int *maxPtr;
    int *minPtr;
    int arr[5];

    for(int i = 0; i < 5; i++){
        scanf("%d", &arr[i]);
    }

    MaxAndMix(&maxPtr, &minPtr, arr);

    printf("%d %d\n", *maxPtr, *minPtr);

    return 0;
}