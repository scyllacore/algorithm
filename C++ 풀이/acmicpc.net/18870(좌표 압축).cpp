#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> crd;
	vector<int> cmp;

	int n, tmp;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		crd.push_back(tmp);
		cmp.push_back(tmp);
	}

	//cmp.resize(crd.size());
	//copy(crd.begin(), crd.end(), cmp.begin());

	sort(cmp.begin(), cmp.end());
	cmp.resize(unique(cmp.begin(), cmp.end()) - cmp.begin());


	for(auto i : crd)
	{
		int result = lower_bound(cmp.begin(), cmp.end(), i) - cmp.begin();
		cout << result << ' ';
	}


}