#include <stdio.h>

int main(){
    for(int i = 0; i < 100; i++){
        if (i % 7 == 0 || i % 9 == 0)
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}

