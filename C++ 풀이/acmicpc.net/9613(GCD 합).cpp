#include <iostream>
#include <vector>

using namespace std;

int gcd(int x, int y) {

	int tmp;

	for (; y != 0;)
	{
		tmp = x % y;
		x = y;
		y = tmp;
	}

	return x;

}

unsigned long long gcdSum(vector<int>& arr) {
	int i, j;
	unsigned long long sum = 0;

	for (i = 0; i < arr.size()-1; i++)
	{
		for (j = i + 1; j < arr.size(); j++)
		{
			sum += gcd(arr[i], arr[j]);
		}
	}

	return sum;

}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n,i,j,num,tmp;

	cin >> n;

	for (i = 0; i < n; i++)
	{
		cin >> num;

		vector<int> arr;

		for (j = 0; j < num; j++) {
			cin >> tmp;
			arr.push_back(tmp);
		}

		cout << gcdSum(arr) << '\n';

	}


}