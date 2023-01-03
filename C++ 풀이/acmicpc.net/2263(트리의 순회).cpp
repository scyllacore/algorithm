#include <iostream>
#define MAX 100001
using namespace std;

int inorder[MAX];
int postorder[MAX];
int idxPos[MAX];

void traversal(int inStart, int inEnd, int postStart, int postEnd) {

	if (inStart > inEnd) // postStart > postEnd
	{
		return;
	}


	int rootIdx = idxPos[postorder[postEnd]];
	cout << inorder[rootIdx] << ' ';

	int leftSize = rootIdx - inStart;
	//int rightSize = inEnd - rootIdx;

	traversal(inStart, rootIdx - 1, postStart, postStart + leftSize - 1); // inStart + leftSize - 1 => rootIdx-1
	traversal(rootIdx + 1, inEnd, postStart + leftSize, postEnd - 1);


}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int i;
	for (i = 1; i <= n; i++) {
		cin >> inorder[i];
		idxPos[inorder[i]] = i;
	}

	for (i = 1; i <= n; i++) {
		cin >> postorder[i];
	}

	traversal(1, n, 1, n);

	return 0;

}

//9
//8 4 9 3 5 2 6 1 7
//8 9 4 5 3 6 7 1 2