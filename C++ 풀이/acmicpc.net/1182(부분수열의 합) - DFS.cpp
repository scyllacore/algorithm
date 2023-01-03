#include <iostream>

using namespace std;

int n, s;
int arr[21] = { 0 };
int cnt = 0;

void DFS(int depth, int sum) {

	if (depth > n) {
		
		if (sum == s) {
			cnt++;
		}
		return;
	}
	
	DFS(depth + 1, sum);
	DFS(depth + 1, sum+arr[depth]);
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> s;
	
	int i;

	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	DFS(1, 0);

	if (s == 0) cnt--;
	cout << cnt;

	return 0;
}