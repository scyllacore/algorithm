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
	bool flag = 0;

	for (i = 0; i <= str.size(); i++) {

		if (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10 + (str[i] - '0');
		}
		else {
			
			if (flag==0) {
				sum += num;
			}
			else {
				sum -= num;
			}

			num = 0;


			if (str[i] == '-') {
				flag = 1;
			}


		}
	}

	cout << sum;



}

