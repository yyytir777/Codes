#include <stdio.h>

int main(){
    int num1, num2, num3;
    printf("�� ���� ������ �Է��Ͻÿ� : ");
    scanf("%d %d %d", &num1, &num2, &num3);

    int result = num1 * num2 + num3;

    printf("%d x %d + %d = %d\n", num1, num2, num3, result);
    return 0;
}