#include <stdio.h>

int main(){
    int n;
    int sum = 0;
    printf("�Է��� ������ ������ �Է��Ͻÿ� : ");
    scanf("%d\n", &n);

    int input;
    for (int i = 0; i < n; i++){
        scanf("%d", &input);
        sum += input;
    }

    double avg = sum / n;
    printf("��� : %lf\n", avg);
    
    return 0;
}

