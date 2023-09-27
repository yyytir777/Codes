#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    int number;
    char name[10];
    double grade;
}Student;

int main(){
<<<<<<< HEAD
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
=======
<<<<<<< HEAD
    char asdf[] = {'1', '2', '3', '4'};
    printf("%s\n\n", asdf);
    printf("%c\n", asdf);
=======
    int num = 10;
    int *ptr1 = &num;
    int *ptr2 = ptr1;

    (*ptr1)++;
    (*ptr2)++;
    printf("%d\n", num);
    return 0;
>>>>>>> a82c6ac9c90dbe50d345321a04ccc1d9bfb01f7c
}
>>>>>>> 9b3d050e3a08f1226aa6c8bfc3b2a38f5d0f58bd
