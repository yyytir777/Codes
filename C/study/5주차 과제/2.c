#include <stdio.h>

int main(){
    int arr[6] = {1,2,3,4,5,6};

    //�� �� ����Ű�� ������
    int *front_ptr = &arr[0];

    //�� �� ����Ű�� ������
    int *rear_ptr = &arr[5];

    for (int i = 0; i < 6; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
    
    //�� �����Ͱ� �� �����ͺ��� �տ� �������� swap
    while(front_ptr < rear_ptr){
        //�� ��ҿ� �� ��Ҹ� �ٲ�
        int tmp = *front_ptr;
        *front_ptr = *rear_ptr;
        *rear_ptr = tmp;

        /*
        �ٲ� �� 
        -> �� �����͸� �ڷ� ��ĭ �̵�
        -> �� �����͸� ������ ��ĭ �̵�
        */
        front_ptr++;
        rear_ptr--;
    }

    for (int i = 0; i < 6; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
    
    return 0;
}