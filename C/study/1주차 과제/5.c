#include <stdio.h>

int main(){
    int num1, num2, num3;
    printf("세 정수를 입력하시오 : ");
    scanf("%d %d %d", &num1, &num2, &num3);

    int result = (num1 - num2) * (num2 + num3) * (num3 % num1);
    printf("결과 : %d\n", result);
    return 0;
}
