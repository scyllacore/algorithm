#include <iostream>
#include <vector>
#define MAX 26

using namespace std;

struct node {
	char left;
	char right;
};

vector<node> v(MAX);

void preOrder(char node) {
	if (node < 0) return;

	cout << (char)(node+65);
	preOrder(v[node].left);
	preOrder(v[node].right);
}

void inOrder(char node) { 
	if (node < 0) return;

	inOrder(v[node].left);
	cout << (char)(node + 65);
	inOrder(v[node].right);
}

void postOrder(char node) {
	if (node < 0) return;

	postOrder(v[node].left);
	postOrder(v[node].right);
	cout << (char)(node + 65);
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
		v[root-65].left = left-65;
		v[root-65].right = right-65;
	}

	preOrder(0);
	cout << '\n';

	inOrder(0);
	cout << '\n';

	postOrder(0);

	return 0;
}