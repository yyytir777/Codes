#include <iostream>
#include <stack>
using namespace std;

/*
홀수 -> No
  
Using Stack :
Using Array : 
Using list :
Using vector : ...?
*/

string VPS(string data){

    stack<char> st;

    for(int i = 0; i < data.size(); i++){
        if(data[i] == '('){

            st.push(data[i]);
        }
        else if(data[i] == ')'){
            if(st.empty() == 1){ //스택이 비어있으면
                return "NO";
            }
            st.pop();
        }
    }
    //for문 다 돈 후 스택에 문자열이 남아있으면 -> no, 남아있지 않으면 -> yes
    if(st.empty() == 1){
        return "YES";
    }
    else{
        return "NO";
    }
}

int main(){
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int right, left;
        bool y;

        string test_data;
        cin >> test_data;

        cout << VPS(test_data) << '\n';

    }
    return 0;
}