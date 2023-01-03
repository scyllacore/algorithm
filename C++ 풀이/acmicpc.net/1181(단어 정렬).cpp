#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(const string word1,const string word2)
{
	if (word1.size() == word2.size())
	{
		return word1.compare(word2) < 0;
	}
	else {
		return word1.size() < word2.size();
	}

}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n,i;

	cin >> n;

	vector<string> word(n);

	for (i = 0; i < n; i++)
	{
		cin >> word[i];
	}

	sort(word.begin(), word.end(), cmp);
	word.erase(unique(word.begin(), word.end()), word.end());

	for (i = 0; i < word.size(); i++)
	{
		cout << word[i] << '\n';
	}


}