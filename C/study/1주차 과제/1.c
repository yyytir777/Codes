#include <stdio.h>

int main(){
    int num1, num2;
    printf("������ �Է��Ͻÿ� : ");
    scanf("%d %d", &num1, &num2);

    int result1 = num1 - num2;
    int result2 = num1 * num2;

    printf("���� : %d\n", result1);
    printf("���� : %d\n", result2);
    return 0;
}

