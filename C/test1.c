#include <stdio.h>

int arr[1000];
float arr1[1000];

int main(){
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }
    
    float sum = 0;
    for(int i = 0; i < n; i++){
        sum += (float)arr[i] / max * 100;
    }

    printf("%f\n", sum / n);
    return 0;
}