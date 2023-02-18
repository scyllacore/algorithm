#include <iostream>
#include <cctype>

using namespace std;

struct node {
	char left, right;
};

node nodes[26];

void preorder(int node) {
	if (node < 0) {
		return;
	}

	cout << (char)(node + 'A');
	preorder(nodes[node].left);
	preorder(nodes[node].right);
}

void inorder(int node) {
	if (node < 0) {
		return;
	}

	inorder(nodes[node].left);
	cout << (char)(node + 'A');
	inorder(nodes[node].right);
}

void postorder(int node) {
	if (node < 0) {
		return;
	}

	postorder(nodes[node].left);
	postorder(nodes[node].right);
	cout << (char)(node + 'A');
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	char root, left, right;

	for (int i = 0; i < n; i++) {
		cin >> root >> left >> right;
		nodes[root - 'A'].left = left - 'A';
		nodes[root - 'A'].right = right - 'A';
	}

	preorder(0);
	cout << '\n';

	inorder(0);
	cout << '\n';

	postorder(0);

	return 0;
}