#include <stdio.h>

int main(){
    int arr[4] = {1,2,3,4};
    printf("%p", arr);
    printf("%p", &arr[0]);
}