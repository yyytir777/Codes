#include <stdio.h>

int main(){
    int num = 100;
    int *ptr = &num;
    int **dptr = &ptr;
    int ***tptr = &dptr;

    printf("%d %d %d\n", *ptr, **dptr, ***tptr);
    return
}