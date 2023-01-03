#include <iostream>
#include <algorithm>

using namespace std;

int arr[10000];

bool nextPermutation(int len)
{
	int i, j;
	i = j = len - 1;

	//arr[i-1] < arr[i]가 맞는 가장 큰 i
	while (i >= 1 && arr[i - 1] >= arr[i]) {
		i--;
	}

	if (i <= 0) { return false; } // 마지막 순열
	
	//arr[i-1]<arr[j]가 맞는 가장 큰 j
	while (j >= 1 && arr[i - 1] >= arr[j]) {
		j--;
	}

	swap(arr[i - 1], arr[j]); // i-1값과 j값 swap
	//이 시점에서 i부터는 이미 내림차순으로 정렬 되어있음

	j = len - 1;


	while (i < j) {
		swap(arr[i], arr[j]);
		i++, j--;
	} // 오름 차순 정렬


	return true;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int i;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}

	if (nextPermutation(n)) {
		for (i = 0; i < n; i++) {
			cout <<  arr[i] << ' ';
		}
	}
	else {
		cout << -1;
	}


	return 0;

}