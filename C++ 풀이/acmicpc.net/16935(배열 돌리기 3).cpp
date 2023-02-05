#include <iostream>
#include <vector>

using namespace std;

int n, m, r;

vector<vector<int>> makeCommand1Array(vector<vector<int>>& arr) {

	int i, j, idx = 0;
	int nSize = arr.size(), mSize = arr[0].size();

	vector<vector<int>> resultArr(nSize, vector<int>(mSize));



	for (i = nSize - 1; i >= 0; i--) {
		for (j = 0; j < mSize; j++) {
			resultArr[idx / mSize][idx % mSize] = arr[i][j];
			idx++;
		}
	}

	return resultArr;
}

vector<vector<int>> makeCommand2Array(vector<vector<int>>& arr) {

	int i, j, idx = 0;
	int nSize = arr.size(), mSize = arr[0].size();

	vector<vector<int>> resultArr(nSize, vector<int>(mSize));

	for (i = 0; i < nSize; i++) {
		for (j = mSize - 1; j >= 0; j--) {
			resultArr[idx / mSize][idx % mSize] = arr[i][j];
			idx++;
		}
	}

	return resultArr;
}

vector<vector<int>> makeCommand3Array(vector<vector<int>>& arr) {

	int i, j, idx = 0;
	int nSize = arr.size(), mSize = arr[0].size();

	vector<vector<int>> resultArr(mSize, vector<int>(nSize));

	for (i = 0; i < mSize; i++) {
		for (j = nSize - 1; j >= 0; j--) {
			resultArr[idx / nSize][idx % nSize] = arr[j][i];
			idx++;
		}
	}

	return resultArr;
}

vector<vector<int>> makeCommand4Array(vector<vector<int>>& arr) {

	int i, j, idx = 0;
	int nSize = arr.size(), mSize = arr[0].size();

	vector<vector<int>> resultArr(mSize, vector<int>(nSize));

	for (i = mSize - 1; i >= 0; i--) {
		for (j = 0; j < nSize; j++) {
			resultArr[idx / nSize][idx % nSize] = arr[j][i];
			idx++;
		}
	}

	return resultArr;
}

vector<vector<int>> makeCommand5Array(vector<vector<int>>& arr) {

	int i, j, idx = 0;
	int nSize = arr.size(), mSize = arr[0].size();

	vector<vector<int>> resultArr(nSize, vector<int>(mSize));

	for (i = nSize / 2; i < nSize; i++) {
		for (j = 0; j < mSize / 2; j++) {
			resultArr[idx / mSize][idx % mSize] = arr[i][j];
			idx++;
		}

		for (j = 0; j < mSize / 2; j++) {
			resultArr[idx / mSize][idx % mSize] = arr[i - nSize / 2][j];
			idx++;
		}
	}

	for (i = nSize / 2; i < nSize; i++) {
		for (j = mSize / 2; j < mSize; j++) {
			resultArr[idx / mSize][idx % mSize] = arr[i][j];
			idx++;
		}

		for (j = mSize / 2; j < mSize; j++) {
			resultArr[idx / mSize][idx % mSize] = arr[i - nSize / 2][j];
			idx++;
		}
	}

	return resultArr;
}

vector<vector<int>> makeCommand6Array(vector<vector<int>>& arr) {

	int i, j, idx = 0;
	int nSize = arr.size(), mSize = arr[0].size();

	vector<vector<int>> resultArr(nSize, vector<int>(mSize));

	for (i = 0; i < nSize / 2; i++) {
		for (j = mSize / 2; j < mSize; j++) {
			resultArr[idx / mSize][idx % mSize] = arr[i][j];
			idx++;
		}

		for (j = mSize / 2; j < mSize; j++) {
			resultArr[idx / mSize][idx % mSize] = arr[i + nSize / 2][j];
			idx++;
		}
	}

	for (i = 0; i < nSize / 2; i++) {
		for (j = 0; j < mSize / 2; j++) {
			resultArr[idx / mSize][idx % mSize] = arr[i][j];
			idx++;
		}

		for (j = 0; j < mSize / 2; j++) {
			resultArr[idx / mSize][idx % mSize] = arr[i + nSize / 2][j];
			idx++;
		}
	}


	return resultArr;
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m >> r;

	vector<vector<int>> arr;
	arr.assign(n, vector<int>(m));

	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (; r--;) {
		int cmd;
		cin >> cmd;

		switch (cmd) {
		case 1:
			arr = makeCommand1Array(arr);
			break;
		case 2:
			arr = makeCommand2Array(arr);
			break;
		case 3:
			arr = makeCommand3Array(arr);
			break;
		case 4:
			arr = makeCommand4Array(arr);
			break;
		case 5:
			arr = makeCommand5Array(arr);
			break;
		case 6:
			arr = makeCommand6Array(arr);
			break;
		}

	}

	for (i = 0; i < arr.size(); i++) {
		for (j = 0; j < arr[0].size(); j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;

}
