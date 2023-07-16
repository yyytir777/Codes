#include <stdio.h>

int main(){
    int n;
    printf("상수 n 입력: ");
    scanf("%d", &n);

    
    int result = 1;
    int k = 0;
    while(result <= n){
        result = 2 * result;
        k += 1;
    }

    printf("공식을 만족하는 k의 최댓값은 %d", k-1);
    return 0;
}

