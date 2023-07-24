#include <stdio.h>

int main(){
    int n = 3;
    int *ptr = &n;

    printf("%d\n", &n);
    printf("%d\n", ptr);
    return 0;
}