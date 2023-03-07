#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define N 1001



int main(){
    int testCnt;
    cin >> testCnt;

    for(int i = 0; i < testCnt; i++){
        int maxStudent;
        int n, m;
        cin >> n >> m;
        int cnt = 0;

        vector<pair<int, int>> studentNumber;
        bool book_check[N] = {false,};

        for(int j = 0; j < m; j++){
            int a, b;
            cin >> a >> b;
            studentNumber.push_back(make_pair(b, a));
        }
        
        sort(studentNumber.begin(), studentNumber.end());

        for(int i = 0; i < m; i++){
            for(int j = studentNumber[i].second; j <= studentNumber[i].first; j++){
                if(book_check[j] == false){
                    book_check[j] = true;
                    cnt++;
                    break;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}