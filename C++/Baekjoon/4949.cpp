#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main(){
    while(true){
        string input;
        getline(cin, input);

        if(input == ".")
            break;
        
        stack<char> s;
        bool check = 1;

        for (int i = 0; i < input.length(); i++)
        {
            if(input[i] == '[' || input[i] == '(')
                s.push(input[i]);

            else if(input[i] == ']'){
                if(!s.empty() && s.top() == '[')
                    s.pop();
                else{
                    check = 0;
                    break;
                }
            }

            else if(input[i] == ')'){
                if(!s.empty() && s.top() == '(')
                    s.pop();
                else{
                    check = 0;
                    break;
                }

            }
        }

        if(s.empty() && check)
            cout << "yes\n";
        else
            cout << "no\n";

    }
    return 0;
}