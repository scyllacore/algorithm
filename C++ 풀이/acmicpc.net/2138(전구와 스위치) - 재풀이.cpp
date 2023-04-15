#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX (int)1e5

int n;

bool isSameBulb(vector<bool>& bulbA, vector<bool>& bulbB) {
	for (int i = 0; i < n; i++) {
		if (bulbA[i] != bulbB[i]) {
			return 0;
		}
	}
	return 1;
}

int changeBulb(vector<bool> bulbA, vector<bool>& bulbB, int start) {

	int count = 0;

	if (start == 0) {
		bulbA[0] = !bulbA[0];
		bulbA[1] = !bulbA[1];
		count++;
	}

	for (int i = 1; i < n; i++) {

		if (bulbA[i - 1] == bulbB[i - 1]) { // 이거 왜 i가 아니고 i-1일까?
			continue;
		}

		if (i - 1 >= 0) {
			bulbA[i - 1] = !bulbA[i - 1];
		}

		bulbA[i] = !bulbA[i];

		if (i + 1 < n) {
			bulbA[i + 1] = !bulbA[i + 1];
		}

		count++;
	}

	if (isSameBulb(bulbA, bulbB)) {
		return count;
	}

	return MAX + 1;
}

int getBulbCount(vector<bool>& bulbA, vector<bool>& bulbB) {

	int countA = changeBulb(bulbA, bulbB, 0);
	int countB = changeBulb(bulbA, bulbB, 1);

	int count = min(countA, countB);

	if (count == MAX + 1) {
		return -1;
	}

	return count;
}

int main() {
	cin >> n;

	vector<bool> bulbA(n), bulbB(n);

	string line;

	cin >> line;
	for (int i = 0; i < n; i++) {
		bulbA[i] = line[i] - '0';
	}

	cin >> line;
	for (int i = 0; i < n; i++) {
		bulbB[i] = line[i] - '0';
	}

	cout << getBulbCount(bulbA, bulbB);
	return 0;
}