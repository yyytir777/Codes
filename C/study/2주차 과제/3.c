#include <stdio.h>

int main(){
    int a, b;
    printf("두 개의 정수를 입력하시오 : ");
    scanf("%d %d", &a, &b);

    int sum = 0;
    for(int i = a; i <= b; i++){
        sum += i;
    }

    printf("정수들의 합 : %d\n", sum);
    return 0;
}

