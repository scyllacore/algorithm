#include <iostream>
#include <queue>

using namespace std;

#define SIZE (int)5e5

struct spotInfo {
	int curTime;
	int curSpot;
};

int n, k;
int visited[2][SIZE + 1];

int printRes() {

	for (int i = 0; i <= SIZE; i++) {
		int curK = k + i * (i + 1) / 2;

		if (curK > SIZE) {
			return -1;
		}

		if (visited[i % 2][curK] != -1 && visited[i % 2][curK] <= i) { // 2. 동생이 누나가 방문한 지점에 접근할 수 있는지 확인한다. 
			return i;
		}
	}

	return -1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> k;

	queue<spotInfo> bfsQ;

	fill(&visited[0][0], &visited[1][SIZE + 1], -1);
	//visited[0][n] = 0; 초기 방문을 처리하지 않는다 이유는 모르겠다.

	bfsQ.push({ 0,n });

	for (; !bfsQ.empty();) {
		int curT = bfsQ.front().curTime;
		int curS = bfsQ.front().curSpot;
		bfsQ.pop();

		if (curS < 0 || curS > SIZE) {
			continue;
		}

		if (visited[curT % 2][curS] != -1) {
			continue;
		}

		visited[curT % 2][curS] = curT;

		bfsQ.push({ curT + 1,curS + 1 });
		bfsQ.push({ curT + 1,curS - 1 });
		bfsQ.push({ curT + 1,curS * 2 });

		//1. 누나가 미리 최단 시간으로 접근할 수 있는 지점을 다 확인한 후,
	}

	cout << printRes();

	return 0;
}

//https://velog.io/@embeddedjune/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%ED%81%B0%EB%8F%8C-Chapter-3-%EC%99%84%EC%A0%84%ED%83%90%EC%83%89%EB%B0%B1%ED%8A%B8%EB%9E%98%ED%82%B9-%EB%B0%B1%EC%A4%80-17071-%EC%88%A8%EB%B0%94%EA%BC%AD%EC%A7%885