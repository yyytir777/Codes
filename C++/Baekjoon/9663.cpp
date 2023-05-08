#include <iostream>
using namespace std;
#define MAX 15

int col[MAX];
int n;
int cnt = 0;

bool promising(int level){
    for(int i = 0; i < level; i++){
        if(col[i] == col[level] || abs(col[level] - col[i]) == level - i)
            return false;
    }
    return true;
}

void queens(int i){
    if(i == n)
        cnt += 1;
    else{
        for(int j = 0; j < n; j++){
            col[i] = j;
            if(promising(i))
                queens(i+1);
        }
    }
}

int main(){
    cin >> n;
    queens(0);
    cout << cnt;
    return 0;
}