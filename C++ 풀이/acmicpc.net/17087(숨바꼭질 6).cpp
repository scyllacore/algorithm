#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int x,int y){

	int tmp;

	for (; y != 0;)
	{
		tmp = x % y;
		x = y;
		y = tmp;
	}

	return x;
}

int gcdMany(vector<int>& distance) {
	
	int i;

	for (i = 1; i < distance.size(); i++)
	{
		distance[i] = gcd(distance[i - 1], distance[i]);
	}

	return distance[distance.size() - 1];
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n,s,a,i;
	vector<int> distance;

	cin >> n >> s;

	for (i = 0; i < n; i++)
	{
		cin >> a;
		distance.push_back(abs(s - a));

	}

	cout << gcdMany(distance);

}