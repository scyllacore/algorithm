	#include <iostream>

	using namespace std;

	#define MAX 31

	long long dp[MAX + 1][MAX + 1] = { {0} };
	string res;

	void findBinary(int N, int L, long long I) {
		if (N <= 0) {
			return;
		}

		if (L <= 0) {
			for (int i = 0; i < N; i++) {
				res += "0";
			}
			return;
		}

		int oneCnt = 0;

		for (int i = 0; i <= L; i++) {
			oneCnt += dp[N - 1][i];
		}

		if (oneCnt >= I) {
			res += "0";
			findBinary(N - 1, L, I);
		}
		else {
			res += "1";
			findBinary(N - 1, L - 1, I - oneCnt);
		}
	}

	int main() {
		cin.tie(NULL);
		cout.tie(NULL);
		ios::sync_with_stdio(false);

		int N, L;
		long long I;

		cin >> N >> L >> I;

		dp[0][0] = 1;
		for (int i = 1; i <= MAX; i++) {
			dp[i][i] = dp[i][0] = 1;
		}

		for (int i = 2; i <= MAX; i++) {
			for (int j = 1; j <= i; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
			}
		}

		findBinary(N, L, I);
		cout << res;

		return 0;
	}

// https://velog.io/@jua0610/%EB%B0%B1%EC%A4%80-2248-%EC%9D%B4%EC%A7%84%EC%88%98-%EC%B0%BE%EA%B8%B0
//https://huiung.tistory.com/123

/*
#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, l, i;

bool isUnderL(int n) {

	int oneCnt = 0;

	for (int i = 0; i < n; i++) {
		if (n & (1 << i)) {
			oneCnt++;
		}
	}

	if (oneCnt <= l) {
		return 1;
	}

	return 0;
}

vector<int> bfs(vector<int>& addedBit) {

	queue<int> bfsQ;
	unordered_set<int> visited;

	vector<int> lBitV;

	for (int i = 0; i < n; i++) {
		bfsQ.push(addedBit[i]);
		visited.insert(addedBit[i]);

		lBitV.push_back(addedBit[i]);
	}


	for (; !bfsQ.empty();) {

		int curVal = bfsQ.front();
		bfsQ.pop();

		for (int i = 0; i < n; i++) {
			int nextVal = (curVal | addedBit[i]);

			if (isUnderL(nextVal) && visited.find(nextVal) == visited.end()) {
				bfsQ.push(nextVal);
				visited.insert(nextVal);
				lBitV.push_back(nextVal);
			}
		}
	}

	return lBitV;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> l >> i;

	vector<int> addedBit;

	for (int i = 0; i < n; i++) {
		addedBit.push_back((1 << i));
	}

	vector<int> lBitV = bfs(addedBit);

	sort(lBitV.begin(), lBitV.end());

	cout << lBitV[i - 1];
}

*/