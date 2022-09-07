#include <iostream>
#include <algorithm>
using namespace std;

int L, C;
char ch[16], sequence[16];
bool isVowel[16];

void DFS(int start, int depth, int consonant, int vowel) {

	int i;

	if (depth > L) {
		if (consonant >= 2 && vowel >= 1) {
			for (i = 1; i <= L; i++)
				cout << sequence[i];
			cout << '\n';
		}
		return;
	}

	for (i = start; i <= C; i++) {
		sequence[depth] = ch[i];
		if (isVowel[i])
			DFS(i + 1, depth + 1, consonant, vowel + 1);
		else
			DFS(i + 1, depth + 1, consonant + 1, vowel);

	}
}
int main() {

	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> L >> C;


	int i;
	for (i = 1; i <= C; ++i) {
		cin >> ch[i];
	}

	sort(ch, ch + (C+1));

	for (i = 1; i <= C; ++i) {
		if (ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u')
			isVowel[i] = true;
	}

	DFS(1, 1, 0, 0);

	return 0;
}