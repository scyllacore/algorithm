#include <iostream>
#include <string>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	int set = 0;
	string cmd;
	int n;

	for (; tc--;) {
		cin >> cmd;

		if (!cmd.compare("add")) {
			cin >> n;
			set |= (1 << n);
		}

		else if (!cmd.compare("remove")) {
			cin >> n;
			set &= ~(1 << n);
		}

		else if (!cmd.compare("check")) {
			cin >> n;

			if (set & (1 << n)) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}

		else if (!cmd.compare("toggle")) {
			cin >> n;
			set ^= (1 << n);
		}

		else if (!cmd.compare("all")) {
			set = (1 << 21) - 1;
		}

		else if (!cmd.compare("empty")) {
			set = 0;
		}
	}

	return 0;

}