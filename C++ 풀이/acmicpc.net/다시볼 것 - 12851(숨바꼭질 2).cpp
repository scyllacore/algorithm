#include <iostream>
#include <queue>

using namespace std;

#define SIZE (int)1e5

struct spotInfo {
	int curS;
	int curT;
};

int n, k;
bool visited[SIZE + 1] = { 0 };

int cnt = 0;

int findEnd() {
	queue<spotInfo> bfsQ;
	bfsQ.push({ n,0 });

	int minT = SIZE + 1;

	for (; !bfsQ.empty();) {
		int curS = bfsQ.front().curS;
		int curT = bfsQ.front().curT;
		bfsQ.pop();

		visited[curS] = 1;

		if (curS == k && minT == curT) {
			cnt++;
		}

		if (curS == k && minT == SIZE + 1) {
			minT = curT;
			cnt++;
		}

		if (curS + 1 <= SIZE && !visited[curS + 1]) {
			bfsQ.push({ curS + 1,curT + 1 });
		}
		if (curS - 1 >= 0 && !visited[curS - 1]) {
			bfsQ.push({ curS - 1,curT + 1 });
		}
		if (curS * 2 <= SIZE && !visited[curS * 2]) {
			bfsQ.push({ curS * 2,curT + 1 });
		}
	}

	return minT;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> k;

	cout << findEnd() << '\n';
	cout << cnt;

	return 0;
}

/*
#include <iostream>
#include <queue>

using namespace std;

#define SIZE (int)1e5

struct spotInfo {
	int curS;
	int curT;
};

int n, k;
int visited[SIZE + 1];

spotInfo findEnd() {
	queue<spotInfo> bfsQ;
	bfsQ.push({ n,0 });

	for (; !bfsQ.empty();) {
		int curS = bfsQ.front().curS;
		int curT = bfsQ.front().curT;
		bfsQ.pop();

		if (curS == k) {
			return bfsQ.front();
		}

		if (curS > SIZE || curS < 0) {
			continue;
		}

		if (visited[curS] != -1) {
			continue;
		}

		visited[curS] = curT;

		bfsQ.push({ curS + 1,curT + 1 });
		bfsQ.push({ curS - 1,curT + 1 });
		bfsQ.push({ curS * 2,curT + 1 });
	}

	return { 0,0 };
}

int countCombi(spotInfo end) {
	queue<spotInfo> bfsQ;
	bfsQ.push(end);

	int cnt = 0;

	for (; !bfsQ.empty();) {
		int curS = bfsQ.front().curS;
		int curT = bfsQ.front().curT;
		bfsQ.pop();


		if (curS > SIZE || curS < 0) {
			continue;
		}

		if (curT < 0) {
			continue;
		}

		if (curS == n) {
			cnt++;
		}

		bfsQ.push({ curS - 1,curT - 1 });
		bfsQ.push({ curS + 1,curT - 1 });

		if (curS % 2 == 0) {
			bfsQ.push({ curS / 2,curT - 1 });
		}
	}

	return cnt;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> k;

	fill(&visited[0], &visited[SIZE + 1], -1);

	spotInfo end = findEnd();

	cout << end.curT << '\n';
	cout << countCombi(end);

	return 0;
}
*/