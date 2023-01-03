#include <iostream>

using namespace std;

int factorial(int n) {

	int sum = 1;
	while (n > 1) {
		sum *= (n--);
	}

	return sum;
}


int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;

	cin >> n >> k;

	cout << factorial(n) / (factorial(n - k) * factorial(k));


}