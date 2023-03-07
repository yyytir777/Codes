#include <iostream>
using namespace std;
#define M 1000000

int tree_length[M];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m; //n = 나무의 수, m = 필요한 나무 길이

    for(int i = 0; i < n; i++){
        cin >> tree_length[i];
    }

    int max = tree_length[0];
    int min = tree_length[0];

    for(int i = 0; i < n; i++){
        if(tree_length[i] < min){
            min = tree_length[i];
        }
        
        if(tree_length[i] > max){
            max = tree_length[i];
        }
    }

    int sum = 0;
    int mid;

    while(min <= max){
        mid = (int)((min + max) / 2);
        
        for(int i = 0; i < n; i++){
            if(tree_length[i] > mid){
                sum += (tree_length[i] - mid);
            }
        }

        if(sum > m){
            min = mid;
            sum = 0;
        }
        else if(sum < m){
            max = mid;
            sum = 0;
        }
        else{
            break;
        }
    }

    cout << mid;
    return 0;
}