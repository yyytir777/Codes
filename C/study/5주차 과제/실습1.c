#include <stdio.h>

int main(){
    int num1 = 100;
    int num2 = 100;
    int *pnum;

    pnum = &num1;
    *pnum += 30;

    printf("num1 : %d\nnum2 : %d\npnum : %p\n", num1, num2, pnum);
    printf("\n");
    pnum = &num2;
    *pnum -= 30;

    printf("num1 : %d\nnum2 : %d\npnum : %p\n", num1, num2, pnum);

    return 0;
}