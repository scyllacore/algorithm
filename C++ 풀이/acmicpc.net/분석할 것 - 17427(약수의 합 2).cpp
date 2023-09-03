#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	unsigned long long sum = 0;

	for (int i = 1; i <= n; i++) {
		sum += i * (n / i); // i는 숫자 , n/i는 숫자의 개수
	}

	cout << sum;
	return 0;

}
//https://mine-it-record.tistory.com/523
//직접 분석 해볼 것