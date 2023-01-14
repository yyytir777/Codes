#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(string a, string b){
    if(a.size() == b.size()){ //두개의 단어의 길이가 같을때
        return a < b; //a, b 순서대로 출력
    }
    else{ //다를때
        return a.size() < b.size(); //a, b 순서대로 출력
    }
}

int main(){
    vector<string> v;
    // v : 단어 입력받아넣음

    int n;
    cin >> n;
    // n : 단어개수

    for(int i = 0; i < n; i++){
        string word;
        cin >> word;
        v.push_back(word);
    }
    //v에 단어 입력 완료

    sort(v.begin(), v.end(), compare);
    //정렬

    /*
    vector<int>::iterator iter;
    //iterator : 벡터의 원소를 참조
    for(iter = v.begin(); iter != v.end(); iter++){

    }
    */

    string a;
    for(int i = 0; i < v.size(); i++){
        if(a == v[i]){
            continue;
        }
        cout << v[i] << '\n';
        a = v[i];
    }
}