#include <iostream>
using namespace std;
/*
순차적으로 순회
1) 같을때
    continue
2) 다를때 
    -arr에 있으면 그룹단어X
    -arr에 없으면 continue
*/
int main(){
    int n;
    cin >> n;
    int cnt = n;

    for(int i = 0; i < n; i++){
        string word;
        cin >> word;
        bool arr[26] = {false,};
        arr[int(word[0]) - 97] = true;

        for(int j = 0; j < word.size() - 1; j++){

            if(word[j] != word[j + 1]){ //다를때
                if(arr[int(word[j + 1] - 97)] == false){
                    arr[int(word[j + 1] - 97)] = true;
                }
                else{
                    cnt--;
                    break;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}