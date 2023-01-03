#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;


/*void reverseOutput(string::iterator ptr, stack<char>& revStr) {

		for (; revStr.size() != 0;) {
			cout << revStr.top();
			revStr.pop();
		}
		cout << ' ';

}*/

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i, j;
	string::iterator ptr; // reversePointer

	cin >> n;
	cin.ignore();

	string* str = new string[n]; // string도 띄어쓰기 포함 안한다

	for (i = 0; i < n; i++)
	{
		getline(cin, str[i]);


		/* 스스로 푼 방식 , stack<char> revStr;

		for (ptr = str[i].begin(); ptr != str[i].end(); ptr++)
		{
			if (*ptr == ' ')
			{
				reverseOutput(ptr, revStr);
			}
			else {
				revStr.push(*ptr);
			}
		}
		reverseOutput(ptr, revStr);*/

		//더 효율적이게

		int startPtr = 0;

		for (ptr= str[i].begin(); ptr != str[i].end(); ptr++) {
			if (*ptr == ' ')
			{
				int revPtr = (int)(ptr - str[i].begin());
				reverse(str[i].begin() + startPtr, str[i].begin() + revPtr);
				startPtr = revPtr + 1;
			}

		}

		reverse(str[i].begin() + startPtr,str[i].end());


		cout << str[i] << '\n';

	}

}