#include <stdio.h>

void Swap(int *ptr1, int *ptr2, int *ptr3){
    int tmp = *ptr3;
    *ptr3 = *ptr2;
    *ptr2 = *ptr1;
    *ptr1 = tmp;
}


int main(){
    int num1 = 10, num2 = 20, num3 = 30;
    printf("num1 : %d\nnum2 : %d\nnum3 : %d\n\n", num1, num2, num3);
    
    Swap(&num1, &num2, &num3);

    printf("num1 : %d\nnum2 : %d\nnum3 : %d\n", num1, num2, num3);
    return 0;
}

