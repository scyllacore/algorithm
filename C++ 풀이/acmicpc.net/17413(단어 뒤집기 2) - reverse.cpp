#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	string str;
	int start,i;

	getline(cin, str);

	for (i = 0; i < str.size(); i++) {
		if (str[i] == '<') {
			while (str[++i] != '>');
		}
		else {
			start = i;

			while (str[++i] != ' ' && str[i] != '<' && i < str.size());
			
			reverse(str.begin() + start, str.begin() + i);
			
			if (str[i] == '<') { i--; }
		
		}

	}
	cout << str;
}