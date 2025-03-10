#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

#define MAX (long long)1e9

struct numInfo {
	int num;
	string operStr;
};

string bfs(int& s, int& t) {

	if (s == t) {
		return "0";
	}

	queue<numInfo> bfsQ;
	unordered_set<int> visited;

	bfsQ.push({ s,"" });
	visited.insert(s);

	auto isRangeNum = [](long long val) -> bool {
		return val >= 1 && val <= MAX;
	};

	for (; !bfsQ.empty();) {
		long long curVal = bfsQ.front().num;
		string curOper = bfsQ.front().operStr;
		bfsQ.pop();

		if (curVal == t) {
			return curOper;
		}

		long long calVal;

		calVal = curVal * curVal;
		if (isRangeNum(calVal) && visited.find(calVal) == visited.end()) {
			visited.insert(calVal);
			bfsQ.push({ (int)calVal,curOper + "*" });
		}

		calVal = curVal + curVal;
		if (isRangeNum(calVal) && visited.find(calVal) == visited.end()) {
			visited.insert(calVal);
			bfsQ.push({ (int)calVal,curOper + "+" });
		}

		calVal = curVal - curVal;
		if (isRangeNum(calVal) && visited.find(calVal) == visited.end()) {
			visited.insert(calVal);
			bfsQ.push({ (int)calVal,curOper + "-" });
		}

		calVal = curVal / curVal;
		if (isRangeNum(calVal) && visited.find(calVal) == visited.end()) {
			visited.insert(calVal);
			bfsQ.push({ (int)calVal,curOper + "/" });
		}
	}


	return "-1";

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int s, t;

	cin >> s >> t;

	cout << bfs(s, t);
	return 0;
}