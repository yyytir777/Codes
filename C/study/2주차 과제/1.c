#include <stdio.h>

int main(){
    int n;
    int sum = 0;
    printf("입력할 정수의 개수를 입력하시오 : ");
    scanf("%d\n", &n);

    int input;
    for (int i = 0; i < n; i++){
        scanf("%d", &input);
        sum += input;
    }

    double avg = sum / n;
    printf("평균 : %lf\n", avg);
    
    return 0;
}

