#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int& x, int& y)
{
	return x > y;
}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int i, n;

	cin >> n;


	int* arr = new int[n];

	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n, compare);


	for (i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	
	delete[] arr;

	return 0;


}