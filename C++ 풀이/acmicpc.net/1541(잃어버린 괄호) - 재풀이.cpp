#include <iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;

	int i;
	int sum = 0, num = 0;

	for (i = 0; i <= str.size(); i++) { // i <= str.size(); '<='로 처리 하는 것은 마지막에 정해진 값까지 누적하기 위함이다.
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10 + (str[i] - '0');
			continue;
		}

		sum += num;
		num = 0;

		if (str[i] == '-') {
			break;
		}
	}

	for (i++; i <= str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10 + (str[i] - '0');
			continue;
		}

		sum -= num;
		num = 0;
	}

	cout << sum;
	return 0;
}


/*
#include <iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;

	int i;
	int sum = 0, num = 0;

	for (i = 0; i < str.size() && str[i] != '-'; i++) {
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10 + (str[i] - '0');
		}
		else {
			sum += num;
			num = 0;
		}
	}

	sum += num;
	num = 0;

	for (i++; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10 + (str[i] - '0');
		}
		else {
			sum -= num;
			num = 0;
		}
	}

	sum -= num;

	cout << sum;
	return 0;
}
*/
