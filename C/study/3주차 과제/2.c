#include <stdio.h>

int recursive(int n){
    if(n == 0)
        return 1;
    else
        return 2 * recursive(n-1);
}

int main(){
    int num;
    printf("���� �Է� : ");
    scanf("%d", &num);

    printf("2�� %d���� : %lld", num, recursive(num));
    return 0;
}