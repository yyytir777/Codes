#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    int number;
    char name[10];
    double grade;
}Student;

int main(){
    int cnt;
    Student* list;

    printf("학생 수를 입력하시오 : ");
    scanf("%d", &cnt);


    list = (student*)malloc(sizeof(Student) * cnt);

    for (int i = 0; i < cnt; i++)
    {
        printf("%d번째 학생 정보 입력 : ", i+1);
        scanf("%d %s %lf", &list[i].number, list[i].name, &list[i].grade);
    }

    int tmp;

    free(list);
}
