#include <iostream>
#include <stack>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int k,n,i;
	cin >> k;

	stack<int> val;

	for (i = 0; i < k; i++) {

		cin >> n;

		if (!val.empty() && n == 0) {
			val.pop();
		}
		else {
			val.push(n);
		}
	}

	int sum = 0;

	for (; !val.empty();)
	{
		sum += val.top();
		val.pop();
	}

	cout << sum;
	return 0;

}