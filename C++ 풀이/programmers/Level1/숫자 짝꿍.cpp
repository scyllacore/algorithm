#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
	int xNumberCnt[10] = { 0 };
	int yNumberCnt[10] = { 0 };

	for (auto x : X) {
		xNumberCnt[x - '0']++;
	}

	for (auto y : Y) {
		yNumberCnt[y - '0']++;
	}

	string answer = "";

	bool onlyZeroCheck = true;

	for (int i = 9; i >= 0; i--) {
		if (xNumberCnt[i] && yNumberCnt[i]) {
			for (int j = 0; j < min(xNumberCnt[i], yNumberCnt[i]); j++) {
				answer += to_string(i);
			}
		}
	}

	for (int i = 9; i >= 1; i--) {
		if (xNumberCnt[i] && yNumberCnt[i]) {
			onlyZeroCheck = false;
		}
	}

	if (xNumberCnt[0] && yNumberCnt[0] && onlyZeroCheck) {
		return "0";
	}

	if (answer.empty()) {
		return "-1";
	}

	return answer;
}