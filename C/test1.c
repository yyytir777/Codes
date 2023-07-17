#include <stdio.h>

void show_digit(int x){
    if(x != 0){
        show_digit(x / 10);
        printf("%d ", x % 10);
    }
}

int main(){
    int n;
    printf("정수를 입력하시오 : ");
    scanf("%d", &n);

    show_digit(n);
    return 0;
}