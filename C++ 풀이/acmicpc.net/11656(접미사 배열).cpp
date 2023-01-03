#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int i,j;
	string str;
	vector<string> suffix;

	cin >> str;

	for (i = 0; i < str.size(); i++)
	{
		string dest;
		
		for (j = i; j < str.size(); j++)
		{
			dest += str[j];
		}

		suffix.push_back(dest);
	}

	sort(suffix.begin(), suffix.end());
	//	sort(suffix.begin()+(인덱스 값), suffix.end()-(인덱스 값));


	for (i = 0; i < suffix.size(); i++)
	{
		cout << suffix[i] << '\n';
	}




}