#include <stdio.h>

int main(){
    int num1, num2, num3;
    printf("세 개의 정수를 입력하시오 : ");
    scanf("%d %d %d", &num1, &num2, &num3);

    int result = num1 * num2 + num3;

    printf("%d x %d + %d = %d\n", num1, num2, num3, result);
    return 0;
}