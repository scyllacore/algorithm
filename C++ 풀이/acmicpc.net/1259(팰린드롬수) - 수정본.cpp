#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string str1,str2;

	for (;;) {

		cin >> str1;

		if (str1[0] == '0') return 0;

		str2 = str1;
		reverse(str2.begin(), str2.end());

		cout << (str1==str2 ? "yes" : "no") << '\n';

	}

	return 0;

}
