#include <iostream>
#include <string>

using namespace std;

int n;

bool DFS_btrk(string& seq) {

	int i;

	int size = seq.size();
	for (i = 1; i <= size / 2; i++) {
		string firstStr = seq.substr(size - i, i);
		string secondStr = seq.substr(size - 2*i, i);

		if (firstStr == secondStr) return 0;
	}

	if (size == n) {
		return 1;
	}


	for (i = 1; i <= 3; i++) {

		seq += to_string(i);

		bool fin = DFS_btrk(seq);

		if (fin) return 1;

		seq.pop_back();

	}

	return 0; //이거 안씀. -> 안쓰면 return 1로 처리됨.

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	string seqNum="";

	DFS_btrk(seqNum);

	cout << seqNum;

	return 0;

}