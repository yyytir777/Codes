#include <iostream>
using namespace std;

int main() {
    string tmp;
    cin >> tmp;

    int result = 0;
    string num = "";
    bool isChecked = 0;
    for(int i = 0; i <= tmp.size(); i++) {
        if(tmp[i] == '-' || tmp[i] == '+' || i == tmp.size()) {
            if(isChecked) {
                result -= stoi(num);
                num = "";
            }
            else {
                result += stoi(num);
                num = "";
            }
        }
        else {
            num += tmp[i];
        }

        if(tmp[i] == '-') isChecked = 1;
    }

    cout << result;
}