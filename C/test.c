#include <stdio.h>
#define PI 3.14

double GetArea(double radius){
    return PI * radius * radius;
}

int main(){
    double r;
    printf("���� �������� �Է��Ͻÿ� : ");
    scanf("%lf", &r);

    printf("���� ������ %lf�Դϴ�.\n", GetArea(r));
}