#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque <int> deq;

    int cnt;
    cin >> cnt;

    for(int i = 0; i < cnt; i++){
        int n; // pushÇÒ Á¤¼ö
        string cmd;
        cin >> cmd;

        if(cmd == "push_front"){
            cin >> n;
            deq.push_front(n);
        }
        else if(cmd == "push_back"){
            cin >> n;
            deq.push_back(n);
        }

        else if(cmd == "pop_front"){
            if(deq.size() == 0){
                cout << "-1" << '\n';
            }
            else{
                cout << deq.front() << '\n';
                deq.pop_front();
            }
        }
        else if(cmd == "pop_back"){
            if(deq.size() == 0){
                cout << "-1" << '\n';
            }
            else{
                cout << deq.back() << '\n';
                deq.pop_back();
            }
        }

        else if(cmd == "size"){
            cout << deq.size() << '\n';
        }
        else if(cmd == "empty"){
            if(deq.size() == 0){
                cout << "1" << '\n';
            }
            else{
                cout << "0" << '\n';
            }
        }

        else if(cmd == "front"){
            if(deq.size() == 0){
                cout << "-1" << '\n';
            }
            else{
                cout << deq.front() << '\n';
            }
        }
        else if(cmd == "back"){
            if(deq.size() == 0){
                cout << "-1" << '\n';
            }
            else{
                cout << deq.back() << '\n';
            }
        }
    }
}