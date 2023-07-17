#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int find_num;
    scanf("%d", &find_num);

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == find_num){
            cnt++;
        }
    }
    
    printf("%d", cnt);
    return 0;
}