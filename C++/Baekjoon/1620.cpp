#include <iostream>
#include <map>
#define MAX 100001
using namespace std;

map<string, int> poketmon_string;
string poketmon_int[MAX];

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int N, M;
    cin >> N >> M;

    string temp;
    for(int i = 1; i <= N; i++) {
        cin >> temp;
        poketmon_string.insert({temp, i});
        poketmon_int[i] = temp;
    }

    for(int i = 0; i < M; i++) {
        cin >> temp;

        //  temp == int일 때
        if(isdigit(temp[0])) {
            cout << poketmon_int[stoi(temp)] << '\n';
        }
        // temp == string일 때
        else {
            cout << poketmon_string.find(temp)->second << '\n';
        }
    }
}