#include <stdio.h>

int main(){
    int a, b;

    for(int a = 0; a < 10; a++){
        for(int b = 0; b < 10; b++){
            if(a + b == 9){
                printf("A = %d  Z = %d\n", a, b);
            }
        }
    }
    return 0;
} 

