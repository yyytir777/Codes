#include <stdio.h>

int main(){
    int num1, num2;
    printf("두 정수를 입력하시오 : ");
    scanf("%d %d", &num1, &num2);

    printf("몫 : %d\n", num1 / num2);
    printf("나머지 : %d\n", num1 % num2);
    return 0;
}