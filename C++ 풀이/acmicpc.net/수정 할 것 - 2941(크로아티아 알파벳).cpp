#include <iostream>
#include <map>

using namespace std;

int main() {
	int answer = 0, i;

	map<string, int> alpha;

	alpha["c="] = 1;
	alpha["c-"] = 1;
	alpha["dz="] = 1;
	alpha["d-"] = 1;
	alpha["lj"] = 1;
	alpha["nj"] = 1;
	alpha["s="] = 1;
	alpha["z="] = 1;

	string str;
	cin >> str;

	for (i = 0; i < str.size(); i++)
	{
		string tmp = "";

		if (str[i] == 'd') {

			tmp = str.substr(i, 3);

			if (alpha.find(tmp) != alpha.end())
			{
				i += 2;
			}

			tmp = str.substr(i, 2);
			if (alpha.find(tmp) != alpha.end())
			{
				i += 1;
			}
		}
		else {
			tmp = str.substr(i, 2);
			if (alpha.find(tmp) != alpha.end())
			{
				i += 1;
			}
		}
		answer++;


	}

	cout << answer;

	return 0;

}