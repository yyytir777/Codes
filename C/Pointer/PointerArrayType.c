#include <stdio.h>

int main(){
    int num1 = 10, num2 = 20, num3 = 30;
    int *ptr1 = &num1;
    int *ptr2 = &num2;
    int *ptr3 = &num3;

    int *ptrArr[] = {ptr1, ptr2, ptr3};
    //ptrArr -> 싱글포인터 *ptrArr -> 더블포인터
    int **dptr = ptrArr;
    
    printf("%d %d %d\n", *(ptrArr), *(ptrArr+1), *(ptrArr+2));
    printf("%d %d %d\n", *(dptr), *(dptr+1), *(dptr+2));
    return 0;
}