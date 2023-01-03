#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct treeNode {
	int left, right;
};

int n;
int nodeIdx=1;
int parentNode[10001] = { 0 }, low[10001], high[10001] = { 0 };

vector<treeNode> graph(10001);

int getRoot(int node) {
	if (parentNode[node] == 0) {
		return node;
	}
	return getRoot(parentNode[node]);

}

void inOrderDFS(int node, int depth) {

	if (graph[node].left > 0) {
		inOrderDFS(graph[node].left, depth + 1);
	}

	low[depth] = min(low[depth], nodeIdx);
	high[depth] = max(high[depth], nodeIdx++);

	if (graph[node].right > 0) {
		inOrderDFS(graph[node].right, depth + 1);
	}
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	int i;
	int parent, child1, child2;

	for (i = 1; i <= n; i++) {

		cin >> parent >> child1 >> child2;

		graph[parent] = { child1,child2 };

		if (child1 != -1) {parentNode[child1] = parent;}
		if (child2 != -1) {parentNode[child2] = parent;}

		low[i] = n;
	}

	int root = getRoot(1);
	inOrderDFS(root, 1);

	int ansBreadth = high[1] - low[1] + 1, ansDepth = 1;
	int tmp;

	for (i = 2; i <= n; i++) {

		tmp = high[i] - low[i] + 1;

		if (tmp > ansBreadth) {
			ansDepth = i;
			ansBreadth = tmp;
		}
	}

	cout << ansDepth << ' ' << ansBreadth;

	return 0;

}


