#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string testcase;

    while(testcase != "0"){
        cin >> testcase;
        string re_testcase = testcase;
        reverse(re_testcase.begin(), re_testcase.end());
        if(testcase == "0"){
            break;
        }

        if(re_testcase == testcase){
            cout << "yes" << '\n';
        }
        else{
            cout << "no" << '\n';
        }
    }
    return 0;
} 