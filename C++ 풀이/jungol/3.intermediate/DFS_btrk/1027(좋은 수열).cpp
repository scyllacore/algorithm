#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;

bool DFS_btrk(int depth, string seq) {

	int i;
	int len = seq.length();

	for (i = 1; i <= len / 2; i++) {
		string frontSeq = seq.substr(len - i, i);
		string backSeq = seq.substr(len - 2 * i, i);

		if (frontSeq == backSeq) return 0;
	}

	if (n == depth) {
		cout << seq;
		return 1;
	}

	for (i = 1; i <= 3; i++) {
		seq += to_string(i);
		if(DFS_btrk(depth + 1, seq)) return 1;
		seq.pop_back();
	}

	return 0;
}

int main() {

	cin >> n;

	DFS_btrk(0, "");

	return 0;

}
