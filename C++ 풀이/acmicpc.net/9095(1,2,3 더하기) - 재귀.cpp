#include <iostream>

using namespace std;

int recursion(int n) {
	if (n == 3) { return 4; }
	else if (n == 2) { return 2; }
	else if (n <= 1) { return 1; }

	return recursion(n - 1) + recursion(n - 2) + recursion(n - 3);
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int tc;

	cin >> tc;

	int n;

	while ((tc--) > 0) {
		cin >> n;
		cout << recursion(n) << '\n';
	}

	return 0;

}