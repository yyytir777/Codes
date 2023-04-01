#include <stdio.h>

int main(){
    int n = 3;
    int *ptr = &n;
    int **pptr = &ptr;
    printf("%d %d %d", **pptr, *ptr, n);
    return 0;
}