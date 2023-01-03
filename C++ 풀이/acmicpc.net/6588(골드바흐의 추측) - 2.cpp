#include <iostream>
#define MAX 1000001

using namespace std;

bool n[MAX] = { false };
void sieve() {
	n[0] = true;
	n[1] = true;
	for (int i = 2; i*i < MAX; i++) {
		if (!n[i]) {
			for (int j = i*i; j < MAX; j+=i) {
				n[j] = true;
			}
		}
	}
	return;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	sieve();
	int m;
	for (;;) {
		cin >> m;
		if (!m) break;
		for (int i = 3; i <= m-i; i += 2) {
			if (!n[i] && !n[m - i]) {
				cout << m << " = " << i << " + " << m - i << '\n';
				break;
			}
		}
	}
	return 0;
}