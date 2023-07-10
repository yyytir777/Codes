#include <stdio.h>

int main(){
    int a1 = 2;
    int b1 = 2;

    int result1 = (++a1) * 2;
    int result2 = (b1++) * 2;

    printf("result1 : %d\n", result1);
    printf("result2 : %d\n", result2);
    printf("%d", b1);
    return 0;
}