#include <iostream>
#include <stack>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cout.precision(2);
	cout << fixed;

	int n, i;
	string postFix;
	double alpha[26];

	stack<double> valStack;
	double tmp1, tmp2;

	cin >> n >> postFix;

	for (i = 0; i < n; i++)
	{
		cin >> alpha[i];
	}


	for (i = 0; i < postFix.size(); i++) {
		if (postFix[i] >= 65 && postFix[i] <= 90)
		{
			valStack.push(alpha[postFix[i]-65]);
		}
		else {

			tmp1 = valStack.top();
			valStack.pop();
			tmp2 = valStack.top();
			valStack.pop(); // 안에 공통코드 끄집어냄.

			if (postFix[i] == '+') {
				valStack.push(tmp2+tmp1);
			}
			else if (postFix[i] == '-') {
				valStack.push(tmp2 - tmp1);
			}
			else if (postFix[i] == '*') {
				valStack.push(tmp2 * tmp1);
			}
			else if (postFix[i] == '/') {
				valStack.push(tmp2 / tmp1);
			}
		}

	}


	cout << valStack.top();


}