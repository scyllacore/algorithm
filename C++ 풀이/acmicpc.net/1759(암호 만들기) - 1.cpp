#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int L, C;
vector<char> consonants;
vector<char> vowels;
vector<char> pwdCass;
vector<string> ans;

int vDepth, cDepth;
int vSize, cSize;

void consonantsDFS(int start, int depth) {

	int i;

	if (depth >= cDepth) {
		vector<char> tmp(L);
		copy(pwdCass.begin(), pwdCass.end(), tmp.begin());
		sort(tmp.begin(), tmp.end());

		string str;

		for (i = 0; i < L; i++) {
			str += tmp[i];
		}

		ans.push_back(str);
		return;
	}

	for (i = start; i < cSize; i++) {
		pwdCass.push_back(consonants[i]);
		consonantsDFS(i + 1, depth + 1);
		pwdCass.pop_back();
	}

}

void vowelsDFS(int start, int depth) {

	int i;

	if (depth >= vDepth) {
		consonantsDFS(0, 0); //오류1 해결
		return;
	}

	for (i = start; i < vSize; i++) {
		pwdCass.push_back(vowels[i]);
		vowelsDFS(i + 1, depth + 1);
		//오류1 코드 : consonantsDFS(0, 0); 
		pwdCass.pop_back();
	}

}


int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> L >> C;
	int i;
	char alpha;

	for (i = 0; i < C; i++) {
		cin >> alpha;

		if (alpha == 'a' || alpha == 'e' || alpha == 'i' || alpha == 'o' || alpha == 'u') {
			vowels.push_back(alpha);
		}
		else {
			consonants.push_back(alpha);
		}

	}

	vSize = vowels.size();
	cSize = consonants.size();

	for (i = 1; (i <= vSize && L - i >= 2); i++) { // 오류3 코드 : i <= vSize; i++)
		vDepth = i;
		cDepth = L - i; //  오류2 코드 : cSize - i; 
		vowelsDFS(0, 0);
	}

	sort(ans.begin(), ans.end());

	for (i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}