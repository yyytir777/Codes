#include <stdio.h>

int main(){
    int arr[10];
    int modified_arr[10];

    int n;
    printf("입력받을 정수의 수를 입력하시오 : ");
    scanf("%d", &n);

    printf("리스트에 저장할 정수 값을 모두 입력하시오 : ");
    //입력받은 tmp를 arr에 저장
    int tmp;
    for(int i = 0; i < n; i++){
        scanf("%d", &tmp);
        arr[i] = tmp;
    }

    int c, d;
    printf("배수 조건에 사용될 양의 정수 하나와 곱해질 정수 하나를 입력하시오 : ");
    scanf("%d %d", &c, &d);

    //c의 배수가 아닐때, modified_arr에 arr * d값 대입
    //c의 배수일때, modified_arr에 arr값 대입
    for(int i = 0; i < n; i++){
        if(arr[i] % c != 0){
            modified_arr[i] = arr[i] * d;
        }
        else{
            modified_arr[i] = arr[i];
        }
    }

    int gap_arr[10];
    int e;
    printf("특정 정수를 입력하시오 : ");
    scanf("%d", &e);

    //특정 정수(e)와 modified_arr의 차이를 gap_arr에 저장
    //(양수 음수 처리 필수)
    for(int i = 0; i < n; i++){
        if(modified_arr[i] > e){
            gap_arr[i] = modified_arr[i] - e;
        }
        else{
            gap_arr[i] = e - modified_arr[i];
        }
    }

    printf("특정 정수와 리스트의 수정된 각 정수와의 값 차이 : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", gap_arr[i]);
    }
    printf("\n");
    
    //최댓값(max)을 gap_arr[0]로 일단 초기화
    //만약 값 차이의 최댓값이 gap_arr[0]보다 클때 조정될것이며
    //설렁 gap_arr[0]이라도 그대로 유지됨 
    int max = gap_arr[0];
    for (int i = 0; i < n; i++)
    {   
        //max보다 gap_arr[i]이 더 클때, max값을 업데이트
        if(max < gap_arr[i]){
            max = gap_arr[i];
        }
    }
    //최솟값(min)을 gap_arr[0]로 일단 초기화
    //이유는 위와 동일
    int min = gap_arr[0];
    for (int i = 0; i < n; i++)
    {   
        //min보다 gap_arr[i]이 더 작을때, min값 업데이트
        if(min > gap_arr[i]){
            min = gap_arr[i];
        }
    }
    
    /*
    gap_arr에서 구한 max, min 값을 토대로, gap_arr와 대응되는 배열인 arr를 이용해
    gap_arr에서 최댓값을때, 최솟값일때 인덱스로 arr의 값들을 출력
    */
    printf("특정 정수와 값 차이가 가장 큰 (수정되기 전의) 정수 : ");
    for (int i = 0; i < n; i++)
    {
        if(gap_arr[i] == max)
            printf("%d ", arr[i]);
    }
    printf("\n");

    printf("특정 정수와 값 차이가 가장 작은 (수정되기 전의) 정수 : ");
    for (int i = 0; i < n; i++)
    {
        if(gap_arr[i] == min)
            printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}