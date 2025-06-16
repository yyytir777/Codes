#include <bits/stdc++.h>
using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++) {
        
		Answer = 0;
		int flag = 0;
		int length;
		string str;
		cin >> length;
		cin >> str;

		for(int i = 0; i < length; i++) {
			if(str[i] == 'A' && str[i+1] == 'B') {
				flag = 1;continue;
			}

			else if(str[i] == 'A' && str[i+1] == 'A') {
				Answer += 2;
				i += 1;
			}

			else if(flag && str[i+1] == 'A') {
				Answer += 1;
			} 
		}


		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}