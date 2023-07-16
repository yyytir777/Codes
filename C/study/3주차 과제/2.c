#include <stdio.h>

int recursive(int n){
    if(n == 0)
        return 1;
    else
        return 2 * recursive(n-1);
}

int main(){
    int num;
    printf("정수 입력 : ");
    scanf("%d", &num);

    printf("2의 %d승은 : %lld", num, recursive(num));
    return 0;
}