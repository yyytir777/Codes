#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
/*
첫번째 : 함수
두번째 : 배열길이
세번째 : 배열
-> deque 사용

R -> 배열의 수 뒤집음(뒤에서부터 읽기)
D -> 첫번째 수 버림 but 배열 비어있으면 error
*/
int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string function, arr;
        int length;
        cin >> function >> length >> arr;

        deque <int> deque;

        string number = "";
        for(int j = 0; j < arr.size(); j++){
            /*
            [ -> continue
            0 ~ 9
            , ] ->
            */
            
            if(arr[j] == '['){
                continue;
            }
            else if('0' <= arr[j] && arr[j] <= '9'){
                number += arr[j];
            }
            else if(arr[j] == ',' || arr[j] == ']'){
                while(1){
                    if(number == ""){
                        break;
                    }
                    deque.push_front(stoi(number));
                    number = "";
                }
            }
            //덱에 배열 삽입
        }
        

        bool reverse = false;
        bool print = true;
        for(int i = 0; i < function.size(); i++){
            if(function[i] == 'R'){
                reverse = !reverse;
            }
            else if(function[i] == 'D'){
                if(deque.empty() == 1){
                    print = false;
                    cout << "error\n";
                    break;
                }
                else{ //not empty
                    if(reverse == true){
                        deque.pop_front();
                    }
                    else{
                        deque.pop_back();
                    }
                }
            }
        }

        if(print == true){ //error가 아니면
            if(reverse == false){ //역순이 아니면
                cout << "[";
                while(1){
                    if(deque.empty() == 1){
                        break;
                    }
                    cout << deque.back();
                    deque.pop_back();
                    if(deque.empty() == 0){
                        cout << ",";
                    }
                }
                cout << "]\n";
            }
            else if(reverse == true){ //역순이면
                cout << "[";
                while(1){
                    if(deque.empty() == 1){
                        break;
                    }
                    cout << deque.front();
                    deque.pop_front();
                    if(deque.empty() == 0){
                        cout << ",";
                    }    
                }
                cout << "]\n";
            }
        }
    }
    return 0;
}