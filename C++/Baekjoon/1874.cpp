#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> s;
vector<char> v;
int arr[100001] = {0,};

int main(){
    int n;
    cin >> n;

    int cnt = 1;
    int tmp;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){

        while(cnt <= arr[i]){
            s.push(cnt);
            cnt += 1;
            v.push_back('+');
        }

        if(s.top() == arr[i]){
            s.pop();
            v.push_back('-');
        }
        else{
            cout << "NO";
            return 0;
        }
    }
        
    

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << '\n';
    }
}