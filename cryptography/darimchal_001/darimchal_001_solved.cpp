#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

int main() {
	char *str = "pa55uc0_";
	int size = sizeof(str) / sizeof(char);

	for(int i = 0; i < size; i++) {
		printf("%x", str[i]);
	}
	printf("\n");
}