#include <iostream>
#include <algorithm>

using namespace std;

int n;
char str[10];
bool numCheck[10]={0};
unsigned long long minVal = 10000000000, maxVal = 0;

void DFS_btrk(int depth,int preNum,unsigned long long sum) {

	int i;

	if (depth > n + 1) {
		
		minVal = min(sum, minVal);
		maxVal = max(sum, maxVal);
		
		return;
	}

	for (i = 0; i <= 9; i++) {

		if (numCheck[i] || (str[depth-1] == '>' && preNum < i) || (str[depth-1] == '<' && preNum > i)) continue;

		numCheck[i] = 1;
		DFS_btrk(depth+1,i,sum*10+i);
		numCheck[i] = 0;

	}

}

void printNum(unsigned long long num) {

	char strTmp[11] = { 0 };
	int i;

	for (i = n; i >= 0; i--) {
		strTmp[i] = (num % 10) + '0';
		num /= 10;
	}

	cout << strTmp <<'\n';

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	int i;

	for (i = 1; i <= n; i++) {
		cin >> str[i];
	}

	for (i = 0; i <= 9; i++) {
		numCheck[i] = 1;
		DFS_btrk(2,i,i);
		numCheck[i] = 0;
	}


	printNum(maxVal);
	printNum(minVal);

	return 0;

}