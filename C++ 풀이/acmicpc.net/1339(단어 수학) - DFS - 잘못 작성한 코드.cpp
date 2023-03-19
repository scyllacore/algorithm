#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct alphaVal {
	char alpha;
	int val;
};

string word[10];
bool visited[11];
int n, maxSum;

vector<alphaVal> alphaMap;

void calSum() {
	int sum = 0;
	int i, j, powTmp;

	for (i = 0; i < n; i++) {
		powTmp = 1;
		for (j = word[i].length() - 1; j >= 0; j--) {
			sum += powTmp * alphaMap[word[i][j] - 'A'].val; // 인덱스가 아닌 알파벳으로 매핑된 값을 찾아야 하기에 이와같은 형태는 사용할 수 없다. 
			powTmp *= 10;
		}
	}

	maxSum = max(maxSum, sum);
}

void dfs(int idx) {

	if (idx >= alphaMap.size()) {
		calSum();
		return;
	}

	for (int i = 10 - alphaMap.size(); i < 10; i++) {

		if (visited[i]) {
			continue;
		}

		alphaMap[idx].val = i;

		visited[i] = true;

		dfs(idx + 1);

		visited[i] = false;
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	int i, j;

	bool alphaCheck[26] = { 0 };

	for (i = 0; i < n; i++) {
		cin >> word[i];
		for (j = 0; j < word[i].length(); j++) {
			alphaCheck[word[i][j] - 'A'] = 1;
		}
	}

	for (i = 0; i < 26; i++) {
		if (alphaCheck[i]) {
			alphaMap.push_back({ (char)(i + 'A') ,0 });
		}
	}

	dfs(0);

	cout << maxSum;
	return 0;
}


