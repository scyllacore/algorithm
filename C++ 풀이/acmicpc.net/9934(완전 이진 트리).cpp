#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> binaryTree;
vector<int> building;

void insertTree(int start, int end, int depth) {

	if (start > end) {
		return;
	}

	int mid = (start + end) / 2;

	binaryTree[depth].push_back(building[mid]);

	insertTree(start, mid - 1, depth + 1);
	insertTree(mid + 1, end, depth + 1);

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int k;
	cin >> k;

	binaryTree.assign(k, vector<int>(0));

	int num;
	for (; cin >> num;) {
		building.push_back(num);
	}

	insertTree(0, building.size() - 1, 0);

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < binaryTree[i].size(); j++) {
			cout << binaryTree[i][j] << ' ';
		}
		cout << '\n';
	}


	return 0;
}

/*
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define SIZE 1025

struct node {
	int before;
	int after;
};

vector<vector<node>> graph;
vector<int> nodeInfo;

bool visited[SIZE] = { 0 };
int depthArr[SIZE] = { 0 };

int idx = 0;

void dfs(int cur) {

	if (graph[cur][0].before == 0 || visited[graph[cur][0].before]) {
		return;
	}

	dfs(graph[cur][0].before);

	visited[cur] = 1;
	graph[cur][0].after = nodeInfo[idx++];
	cout << graph[cur][0].before << ' ' << graph[cur][0].after << '\n';

	dfs(graph[cur][1].before);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	nodeInfo.assign((int)pow(2, n - 1) - 1, 0);

	for (int i = 0; i < nodeInfo.size(); i++) {
		cin >> nodeInfo[i];
	}

	graph.assign((int)pow(2, n), vector<node>(2, { 0,0 }));

	int nodeN = 2;

	for (int i = 1; i <= (int)pow(2, n - 1) - 1; i++) {
		graph[i][0].before = nodeN++;
		graph[i][1].before = nodeN++;
	}

	dfs(1);


}

*/