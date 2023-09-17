#include <stdio.h>

int main(){
    int arr[6] = {1,2,3,4,5,6};

    //맨 앞 가리키는 포인터
    int *front_ptr = &arr[0];

    //맨 뒤 가리키는 포인터
    int *rear_ptr = &arr[5];

    for (int i = 0; i < 6; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
    
    //앞 포인터가 뒤 포인터보다 앞에 있을때만 swap
    while(front_ptr < rear_ptr){
        //앞 요소와 뒷 요소를 바꿈
        int tmp = *front_ptr;
        *front_ptr = *rear_ptr;
        *rear_ptr = tmp;

        /*
        바꾼 후 
        -> 앞 포인터를 뒤로 한칸 이동
        -> 뒤 포인터를 앞으로 한칸 이동
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