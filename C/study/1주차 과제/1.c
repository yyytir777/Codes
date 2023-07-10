#include <stdio.h>

int main(){
    int num1, num2;
    printf("Á¤¼ö¸¦ ÀÔ·ÂÇÏ½Ã¿À : ");
    scanf("%d %d", &num1, &num2);

    int result1 = num1 - num2;
    int result2 = num1 * num2;

    printf("»¬¼À : %d\n", result1);
    printf("°ö¼À : %d\n", result2);
    return 0;
}

