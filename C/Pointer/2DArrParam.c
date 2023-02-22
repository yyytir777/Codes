#include <stdio.h>

void ShowArr2DStyle(int (*arr)[2], int column){
    for(int i = 0; i < column; i++){
        for(int j = 0; j < 2; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int Sum2DArr(int arr[][2], int column){
    int sum = 0;
    for(int i = 0; i < column; i++){
        for(int j = 0; j < 2; j++){
            sum += arr[i][j];
        }
    }
    return sum;
}

int main(){
    int arr1[4][2] = {1,2,3,4,5,6,7,8};
    int arr2[6][2] = {1,1,1,1,3,3,3,3,5,5,5,5};

    ShowArr2DStyle(arr1, sizeof(arr1) / sizeof(arr1[0]));
    ShowArr2DStyle(arr2, sizeof(arr2) / sizeof(arr2[0]));

    printf("arr1의 합 : %d\n", Sum2DArr(arr1, sizeof(arr1) / sizeof(arr1[0])));
    printf("arr2의 합 : %d\n",  Sum2DArr(arr2, sizeof(arr2) / sizeof(arr2[0])));
    return 0;
}