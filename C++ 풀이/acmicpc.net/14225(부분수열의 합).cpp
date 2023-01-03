#include <iostream>

using namespace std;

int n;
bool visited[2000001] = { 0 };
int* arr;

void DFS(int idx, int sum) {

	if (idx >= n) {
		visited[sum] = 1;
		return;
	}

	DFS(idx + 1, sum + arr[idx]);
	DFS(idx + 1, sum);

}


int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	arr = new int[n];

	int i;

	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}

	DFS(0,0);

	for (i = 1; i <= 2000000; i++) {
		if (!visited[i]) {
			cout << i;
			return 0;
		}
	}

}
