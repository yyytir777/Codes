#include <stdio.h>

int main(){
    int num1, num2, num3;
    printf("�� ������ �Է��Ͻÿ� : ");
    scanf("%d %d %d", &num1, &num2, &num3);

    int result = (num1 - num2) * (num2 + num3) * (num3 % num1);
    printf("��� : %d\n", result);
    return 0;
}
