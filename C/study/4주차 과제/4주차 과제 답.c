#include <stdio.h>

int main(){
    int arr[10];
    int modified_arr[10];

    int n;
    printf("�Է¹��� ������ ���� �Է��Ͻÿ� : ");
    scanf("%d", &n);

    printf("����Ʈ�� ������ ���� ���� ��� �Է��Ͻÿ� : ");
    //�Է¹��� tmp�� arr�� ����
    int tmp;
    for(int i = 0; i < n; i++){
        scanf("%d", &tmp);
        arr[i] = tmp;
    }

    int c, d;
    printf("��� ���ǿ� ���� ���� ���� �ϳ��� ������ ���� �ϳ��� �Է��Ͻÿ� : ");
    scanf("%d %d", &c, &d);

    //c�� ����� �ƴҶ�, modified_arr�� arr * d�� ����
    //c�� ����϶�, modified_arr�� arr�� ����
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
    printf("Ư�� ������ �Է��Ͻÿ� : ");
    scanf("%d", &e);

    //Ư�� ����(e)�� modified_arr�� ���̸� gap_arr�� ����
    //(��� ���� ó�� �ʼ�)
    for(int i = 0; i < n; i++){
        if(modified_arr[i] > e){
            gap_arr[i] = modified_arr[i] - e;
        }
        else{
            gap_arr[i] = e - modified_arr[i];
        }
    }

    printf("Ư�� ������ ����Ʈ�� ������ �� �������� �� ���� : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", gap_arr[i]);
    }
    printf("\n");
    
    //�ִ�(max)�� gap_arr[0]�� �ϴ� �ʱ�ȭ
    //���� �� ������ �ִ��� gap_arr[0]���� Ŭ�� �����ɰ��̸�
    //���� gap_arr[0]�̶� �״�� ������ 
    int max = gap_arr[0];
    for (int i = 0; i < n; i++)
    {   
        //max���� gap_arr[i]�� �� Ŭ��, max���� ������Ʈ
        if(max < gap_arr[i]){
            max = gap_arr[i];
        }
    }
    //�ּڰ�(min)�� gap_arr[0]�� �ϴ� �ʱ�ȭ
    //������ ���� ����
    int min = gap_arr[0];
    for (int i = 0; i < n; i++)
    {   
        //min���� gap_arr[i]�� �� ������, min�� ������Ʈ
        if(min > gap_arr[i]){
            min = gap_arr[i];
        }
    }
    
    /*
    gap_arr���� ���� max, min ���� ����, gap_arr�� �����Ǵ� �迭�� arr�� �̿���
    gap_arr���� �ִ�����, �ּڰ��϶� �ε����� arr�� ������ ���
    */
    printf("Ư�� ������ �� ���̰� ���� ū (�����Ǳ� ����) ���� : ");
    for (int i = 0; i < n; i++)
    {
        if(gap_arr[i] == max)
            printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Ư�� ������ �� ���̰� ���� ���� (�����Ǳ� ����) ���� : ");
    for (int i = 0; i < n; i++)
    {
        if(gap_arr[i] == min)
            printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}