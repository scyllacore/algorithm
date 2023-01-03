#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
char Bomboni[50][50]={{0}};

int maxCandy(){
	int i, j;
	int maxVal = 0;
	int cnt;

	for (i = 0; i < n; i++) {
		cnt = 1;
		for (j = 1; j < n; j++) {
			if (Bomboni[i][j] == Bomboni[i][j - 1]) { cnt++; }
			else{ maxVal = max(cnt, maxVal),cnt=1; }
		}
		maxVal = max(cnt, maxVal);
	}


	for (i = 0; i < n; i++) {
		cnt = 1;
		for (j = 1; j < n; j++) {
			if (Bomboni[j][i] == Bomboni[j-1][i]) { cnt++; }
			else { maxVal = max(cnt, maxVal), cnt = 1; }
		}
		maxVal = max(cnt, maxVal);
	}

	return maxVal;

}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int i, j, ans = 0;
	cin >> n;

	//vector<vector<char>> Bomboni(n, vector<char>(n, 0));

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> Bomboni[i][j];
		}
	}


	for (i = 0; i < n; i++) {

		for (j = 0; j < n-1; j++) {
			swap(Bomboni[i][j], Bomboni[i][j + 1]);
			ans = max(maxCandy(),ans);
			swap(Bomboni[i][j], Bomboni[i][j + 1]);

			swap(Bomboni[j][i], Bomboni[j+1][i]);
			ans = max(maxCandy(), ans);
			swap(Bomboni[j][i], Bomboni[j+1][i]);
		}
	}


	cout << ans;

	return 0;
}