#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n;
char inequalSign[10];
int combiArr[11];
bool visited[10] = { 0 };
string maxAns = "0", minAns = "9999999999";


void DFS(int depth) {

	int i;

	if (depth > n + 1) {

		for (i = 1; i <= n; i++) {
			if (inequalSign[i] == '<') {
				if (combiArr[i] > combiArr[i + 1]) return;
			}
			else if (inequalSign[i] == '>') {
				if (combiArr[i] < combiArr[i + 1]) return;

			}
		}

		string num;

		for (i = 1; i <= n + 1; i++) {
			num += (char)(combiArr[i]+48);
		}

		if (num.compare(maxAns) > 0) {
			maxAns = num;
		}
		if (num.compare(minAns) < 0) {
			minAns = num;
		}

		return;
	}

	for (i = 0; i <= 9; i++) {
		if (visited[i]) continue;

		combiArr[depth] = i;
		visited[i] = 1;
		DFS(depth + 1);
		visited[i] = 0;

	}

}

int numLenCheck(unsigned long long n) {

	int cnt = 0;

	while (n > 0) {
		cnt++;
		n /= 10;
	}

	return cnt;

}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	int i;

	for (i = 1; i <= n; i++) {
		cin >> inequalSign[i];
	}

	DFS(1);

	cout << maxAns << '\n';
	cout << minAns;

	return 0;


}