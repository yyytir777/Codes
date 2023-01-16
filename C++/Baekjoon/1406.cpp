#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    list<char> editor;
    //editor char형 linked list 선언

    string str;
    cin >> str;

    
    for(int i = 0; i < str.size(); i++){
        editor.push_back(str[i]);
        //문자열을 editor에 insert
    }

    int cnt;
    cin >> cnt;
    string tmp;

    list<char>::iterator cursor = editor.end();
    //editor의 끝을 가리키는 iterator 선언 -> 커서를 표현하기 위해

    for(int i = 0; i < cnt; i++){
        cin >> tmp;
        if(tmp == "L"){ 
        //커서를 왼쪽으로 한칸 옮김 & 문장의 맨 앞이면 무시
            if(cursor == editor.begin()){
                break;
            }
            else{
                cursor--; 
            }
        }

        else if(tmp == "D"){
        //커서를 오른쪽으로 한칸 옮김 & 문장의 맨 뒤이면 무시
            if(cursor == editor.end()){
                break;
            }
            else{
                cursor++;
            }
        }

        else if(tmp == "B"){
        //커서 왼쪽에 있는 문자를 삭제 & 문장의 맨 앞이면 무시
            if(cursor == editor.begin()){
                break;
            }
            else{
                editor.erase(--cursor);
            }
        }
        
        else if(tmp == "P"){  
            char add;
            cin >> add;
            editor.insert(cursor, add);
        }
    }

    list<char>::iterator iter;

    for(iter = editor.begin(); iter != editor.end(); iter++){
        cout << *iter;
    }
    return 0;
}