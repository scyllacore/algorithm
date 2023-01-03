#include <iostream>
#include <stack>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;

	stack<char> chStack;
	int i;
	int sum = 0, num = 0;

	for (i = 0; i <= str.size(); i++) {

		if (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10 + (str[i] - '0');
		}
		else {

			if (chStack.empty() && str[i] == '-') {
				chStack.push(str[i]);
			}
			else if (!chStack.empty()) { // else로 하면 안된다. 조건을 넣어 stack이 존재할 시에만 -를 곱해준다.
				num *= -1;
			}

			sum += num;

			//cout << num << '\n';
			num = 0;

		}
	}

	cout << sum;



}

