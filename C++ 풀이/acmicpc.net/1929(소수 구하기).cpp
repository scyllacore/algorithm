#include <iostream>

using namespace std;

#define MAX 1000001

bool prime[MAX] = { 1,1 };

void eratos(int n) {

	int i, j;

	for (i = 2; i <= n / i; i++) {
		if (!prime[i]) {
			for (j = i * i; j <= n; j += i) {
				prime[j] = 1;
			}
		}

	}


}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int m, n;

	cin >> m >> n;

	eratos(n);

	for (int i = m; i <= n; i++) {
		if (!prime[i]) {
			cout << i << '\n';
		}
	}

	return 0;

}
