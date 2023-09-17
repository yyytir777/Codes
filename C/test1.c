#include <stdio.h>

int main(){
<<<<<<< HEAD
    char asdf[] = {'1', '2', '3', '4'};
    printf("%s\n\n", asdf);
    printf("%c\n", asdf);
=======
    int num = 10;
    int *ptr1 = &num;
    int *ptr2 = ptr1;

    (*ptr1)++;
    (*ptr2)++;
    printf("%d\n", num);
    return 0;
>>>>>>> a82c6ac9c90dbe50d345321a04ccc1d9bfb01f7c
}