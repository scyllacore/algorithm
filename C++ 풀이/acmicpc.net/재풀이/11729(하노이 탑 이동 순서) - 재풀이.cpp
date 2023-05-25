#include <iostream>
#include <cmath>

using namespace std;

void move(int from, int to) {
	cout << from << ' ' << to << '\n';
}

void hanoi(int n, int from, int via, int to) {
	if (n == 1) {
		move(from, to);
		return;
	}

	hanoi(n - 1, from, to, via);
	move(from, to);
	hanoi(n - 1, via, from, to); // n이 2일 때를 생각하면서 코드를 짜도록 하자.
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	cout << (int)pow(2, n) - 1 << '\n';
	hanoi(n, 1, 2, 3);

	return 0;
}