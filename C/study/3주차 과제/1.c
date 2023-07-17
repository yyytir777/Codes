#include <stdio.h>

int max(int n1, int n2, int n3){
    if(n1 > n2)
    {
        if(n1 > n3)
            return n1;
        else
            return n3;
    }
    else
    {
        if(n2 > n3)
            return n2;
        else
            return n3;
    }
}

int min(int n1, int n2, int n3){
    if(n1 < n2){
        if(n1 < n3)
            return n1;
        else
            return n3;
    }
    else{
        if(n2 < n3)
            return n2;
        else
            return n3;
    }
}

int main(){
    int a, b, c;
    printf("세 개의 정수를 입력하시오 : ");
    scanf("%d %d %d", &a, &b, &c);

    printf("가장 큰 수 : %d\n", max(a, b, c));
    printf("가장 작은 수 : %d\n", min(a, b, c));
    return 0;
}