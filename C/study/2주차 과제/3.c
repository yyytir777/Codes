#include <stdio.h>

int main(){
    int a, b;
    printf("�� ���� ������ �Է��Ͻÿ� : ");
    scanf("%d %d", &a, &b);

    int sum = 0;
    for(int i = a; i <= b; i++){
        sum += i;
    }

    printf("�������� �� : %d\n", sum);
    return 0;
}

