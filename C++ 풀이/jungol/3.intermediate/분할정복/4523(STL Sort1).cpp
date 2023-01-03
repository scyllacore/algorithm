#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	//cin.tie(NULL);
	//ios::sync_with_stdio(false);

	int i,n,s,e;
	cin >> n;
	int* arr = new int[n];

	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cin >> s >> e;


	sort(arr + s, arr + e + 1);

	for (i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}

	cout << '\n';

	
	sort(arr, arr+n);

	for (i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}

	delete[] arr;
}