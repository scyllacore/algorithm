#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
char str[10];
bool numCheck[10] = { 0 };
string minVal, maxVal;

void DFS_btrk(int depth, int preNum, string sum) {

	int i;

	if (depth > n + 1) {

		if (sum.compare(minVal) < 0) minVal = sum;
		if (sum.compare(maxVal) > 0) maxVal = sum;

		return;
	}

	for (i = 0; i <= 9; i++) {

		if (numCheck[i] || (str[depth - 1] == '>' && preNum < i) || (str[depth - 1] == '<' && preNum > i)) continue;

		numCheck[i] = 1;
		DFS_btrk(depth + 1, i, sum + to_string(i));
		numCheck[i] = 0;

	}

}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	minVal = "999999999";
	maxVal = "0";


	cin >> n;

	int i;

	for (i = 1; i <= n; i++) {
		cin >> str[i];
	}

	for (i = 0; i <= 9; i++) {
		numCheck[i] = 1;
		DFS_btrk(2, i, to_string(i));
		numCheck[i] = 0;
	}


	cout << maxVal << '\n';
	cout << minVal;

	return 0;

}