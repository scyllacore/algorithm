#include <iostream>
#include <cstdbool>
#include <string>
#include <stack>
#include <queue>

using namespace std;

void revOut(stack<char>& revWord)
{


	while (!revWord.empty())
	{
		cout << revWord.top();
		revWord.pop();
	}

	

}


void fwdOut(queue<char>& fwdWord){

	while (!fwdWord.empty())
	{
		cout << fwdWord.front();
		fwdWord.pop();
	}
}



int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	stack<char> revWord;
	queue<char> fwdWord;

	int i;
	bool flag = 0;

	getline(cin, str);

	for (i = 0; i < str.size(); i++)
	{
		if (str.at(i) == '<') { flag = 1 , revOut(revWord);}

		if (flag == 1) {
			fwdWord.push(str.at(i));
			if (str.at(i) == '>') {
				fwdOut(fwdWord);
				flag = 0;
			}
		}
		else {
			if (str.at(i) == ' ')
			{
				revOut(revWord);
				cout << ' ';
			}
			else {
				revWord.push(str.at(i));
			}

		}

	}

	revOut(revWord);


	return 0;
}

