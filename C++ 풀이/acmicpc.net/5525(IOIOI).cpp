#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	string str;

	cin >> n >> m >> str;


	int ansCnt = 0;

	int i,OILen;

	for (i = 0; i<m ;i++) {

		OILen = 0;

		if (str[i] == 'O') continue;

		while (str[i + 1] == 'O' && str[i + 2] == 'I') {

			OILen++;
			if (OILen == n) {
				OILen--;
				ansCnt++;
			}
			i += 2;
		}
	
		OILen = 0;

	}

	cout << ansCnt;

	return 0;

}