#include <stdio.h>

int main(){
    int num = 10;
    int * ptr1;
    ptr1 = &num;

    //int형 포인터변수에 포인터주소값 저장
    int *ptr2;
    ptr2 = ptr1;

    printf("%d\n", ptr1);
    (*ptr1)++; // num = 11
    (*ptr2)++; // 주소값에 +1

    printf("%d", num);
}