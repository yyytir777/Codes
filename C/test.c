#include <stdio.h>
#define PI 3.14

double GetArea(double radius){
    return PI * radius * radius;
}

int main(){
    double r;
    printf("원의 반지름을 입력하시오 : ");
    scanf("%lf", &r);

    printf("원의 면적은 %lf입니다.\n", GetArea(r));
}