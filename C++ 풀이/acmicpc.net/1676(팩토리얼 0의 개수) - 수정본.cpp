#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i;
	int cnt = 0;

	cin >> n;

	for (i=5; i<=n; i*=5)
	{
		cnt += (n / i);
	}

	cout << cnt;

	return 0;

}

