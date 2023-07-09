#include <stdio.h>


int main(){
    int x1 = 2;
    int x2 = 2;

    int result1 = (++x1) * 2;
    int result2 = (x2++) * 2;

    printf("result1 : %d\nresult2 : %d\n", result1, result2);
    printf("x1 : %d\nx2 : %d\n", x1, x2);
}