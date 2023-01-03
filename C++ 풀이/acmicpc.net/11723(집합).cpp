#include <iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	int n, i, j;
	string str;
	int bit = 0;

	for (i = 1; i <= tc; i++) {
		cin >> str;

		if (str[0] == 'a') {
			if (str[1] == 'd') {
				cin >> n;
				bit |= (1 << n);
			}
			else {
				bit = (1 << 21) - 1;

			}
		}
		else if (str[0] == 'r') {
			cin >> n;
			bit &= ~(1 << n);

		}
		else if (str[0] == 'c') {
			cin >> n;
			if (bit & (1 << n)) { cout << 1 << '\n'; }
			else { cout << 0 << '\n'; }
		}
		else if (str[0] == 't') {
			cin >> n;
			bit ^= (1 << n);
		}
		else if (str[0] == 'e') {
			bit = 0;
		}


	}

	return 0;

}
