#include <iostream>

using namespace std;

int n, r, c;
int ans = 0;

int pow2(int n) {

	int res = 1;

	while ((n--) > 0)
	{
		res *= 2;
	}

	return res;
}

void zDFS(int y, int x, int size) {

	if (y == r && x == c) {
		cout << ans;
		//return;
		exit(0); //결과만 나오면 끝남으로 이렇게 하는게 낫을 듯.
	}


	if (r >= y && r < y + size && c >= x && c < x + size) {
		zDFS(y, x, size / 2);
		zDFS(y, x + size / 2, size / 2);
		zDFS(y + size / 2, x, size / 2);
		zDFS(y + size / 2, x + size / 2, size / 2);
	}
	else {
		ans += size * size;
	}

}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> r >> c;

	zDFS(0, 0, pow2(n));

	//cout << ans; 여기 쓰면 안된다. 


	return 0;
}