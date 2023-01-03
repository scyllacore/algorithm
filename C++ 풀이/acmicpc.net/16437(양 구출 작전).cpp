#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 123456+1

struct nodeInfo {
	int unitN;
	char unitType;
	
};

nodeInfo island[MAX] = { 0 };

vector<vector<int>> areaNode;
int n;

long long DFS_btrk(int curNode) {

	int i;
	int nextNode;
	long long total = 0;


	for (i = 0; i < areaNode[curNode].size(); i++) {
		nextNode = areaNode[curNode][i];
		total += DFS_btrk(nextNode);
	}

	if (island[curNode].unitType == 'W') {
		total -= island[curNode].unitN;

		if (total < 0) return 0;
		else return total;

	}
	else {
		return total + island[curNode].unitN;
	}


}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;	
	areaNode.assign(n + 1, vector<int>(0));

	int i;
	int unitN,dist;
	char unitType;

	island[1].unitType = 'S';
	island[1].unitN = 0;

	for (i = 2; i <= n; i++) {
		cin >> unitType >> unitN >> dist;
		island[i].unitType = unitType;
		island[i].unitN = unitN;
		areaNode[dist].push_back(i);	
	}

	cout << DFS_btrk(1);

	return 0;
}

