#include <stdio.h>

int main(){
    int n;
    printf("��� n �Է�: ");
    scanf("%d", &n);

    
    int result = 1;
    int k = 0;
    while(result <= n){
        result = 2 * result;
        k += 1;
    }

    printf("������ �����ϴ� k�� �ִ��� %d", k-1);
    return 0;
}

