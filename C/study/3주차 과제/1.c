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
    printf("�� ���� ������ �Է��Ͻÿ� : ");
    scanf("%d %d %d", &a, &b, &c);

    printf("���� ū �� : %d\n", max(a, b, c));
    printf("���� ���� �� : %d\n", min(a, b, c));
    return 0;
}