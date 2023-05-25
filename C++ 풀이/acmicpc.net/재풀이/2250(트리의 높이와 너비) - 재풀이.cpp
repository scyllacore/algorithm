#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX (int)1e4

struct node {
	int left, right;
};

vector<node> graph;
int parent[MAX + 1] = { 0 };

int minLeft[MAX / 10], maxRight[MAX / 10];
int nodeIdx = 1;
int maxDepth = 1;

int getRoot(int node) {
	if (!parent[node]) {
		return node;
	}

	return getRoot(parent[node]);
}

void dfs(int depth, int node) {
	if (node < 0) {
		maxDepth = max(depth - 1, maxDepth);
		return;
	}

	dfs(depth + 1, graph[node].left);

	minLeft[depth] = min(nodeIdx, minLeft[depth]);
	maxRight[depth] = max(nodeIdx++, maxRight[depth]);

	dfs(depth + 1, graph[node].right);
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	graph.assign(n + 1, { 0,0 }); // 구조체 초기화 주의
	fill(&minLeft[0], &minLeft[MAX / 10], n);
	fill(&maxRight[0], &maxRight[MAX / 10], 1);


	int r, a, b;

	for (int i = 0; i < n; i++) {
		cin >> r >> a >> b;
		graph[r].left = a;
		graph[r].right = b;

		if (a > 0) {
			parent[a] = r;
		}
		if (b > 0) {
			parent[b] = r;
		}
	}

	int root = getRoot(1);

	dfs(1, root);


	int answerIdx = 0;
	int answer = 0; // 1을 쓰면 너비가 1인 level이 반영이 되지 않는다.


	for (int i = 1; i <= maxDepth; i++) {
		if ((maxRight[i] - minLeft[i] + 1) > answer) {
			answerIdx = i;
			answer = maxRight[i] - minLeft[i] + 1;
		}
	}

	cout << answerIdx << ' ' << answer;

	return 0;
}