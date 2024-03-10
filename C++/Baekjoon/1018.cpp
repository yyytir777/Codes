#include <iostream>
using namespace std;
/*
m x n
m = ��(row)
n = ��(column)

1) iȦ�� ->
    jȦ�� : W
    j¦�� : B
2) i¦�� ->
    jȦ�� : B
    j¦�� : W
*/

int main(){
    int m, n;
    cin >> m >> n;
    int cnt = 0;

    char arr = new char[m][n];

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i % 2 != 0){ //i Ȧ��
                if(j % 2 != 0){
                    arr[i][j] = 'W';
                }
                else{
                    arr[i][j] = 'B';
                }
            }
            else{
                if(j % 2 !=){
                    arr[i][j] = 'B';
                }
                else{
                    arr[i][j] = 'W';
                }
            }
        }
    }

    for(int i = 0; i < m; i++){
        string str;
        cin >> str;
        for(int j = 0; j < str.size() - 1; j++){
            if(str[j] == arr[i][j + 1]){
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}