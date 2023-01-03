#include <iostream>
#include <map>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	map<string, string> siteAndPwd;

	int n, m;
	cin >> n >>  m;

	int i;
	string site, pwd;

	for (i = 0; i < n; i++) {
		cin >> site >> pwd;
		siteAndPwd.insert({ site,pwd });
	}

	for (i = 0; i < m; i++) {
		cin >> site;
		cout << siteAndPwd[site] << '\n';
	}

	return 0;
}
