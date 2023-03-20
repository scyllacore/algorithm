#include <iostream>

using namespace std;

#define MAX (int)2e6

int n;
bool visited[MAX+1] = { 0 };
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

	delete[] arr;

	for (i = 1; i <= MAX; i++) {
		if (!visited[i]) {
			cout << i;
			return 0;
		}
	}
}
