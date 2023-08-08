#include <iostream>
#include <vector>
using namespace std;

//1<=k<=10
//2^k
int input[10024];
int k;
vector<int> arr[10];
void insertTree(int depth, int start, int end) {

	if (start >= end) {
		return;
	}
	int mid = (start + end) / 2;
	arr[depth].push_back(input[mid]);
	insertTree(depth + 1, start, mid);
	insertTree(depth + 1, mid + 1, end);

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> k;


	int num;
	int idx = 0;
	while (cin >> num) {
		input[idx++] = num;
	}
	insertTree(0, 0, idx);
	for (int i = 0; i < k; i++) {
		for (auto o : arr[i]) {
			cout << o << ' ';
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