#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<string> babblingInput) {
	vector<string> babbling = { "aya", "ye", "woo", "ma" };
	vector<string> repeatedBabbling = { "ayaaya", "yeye", "woowoo", "mama" };

	int answer = 0;

	for (int i = 0; i < babblingInput.size(); i++) {
		for (string bab : repeatedBabbling) {
			size_t pos = babblingInput[i].find(bab);
			if (pos != string::npos) {
				babblingInput[i].replace(pos, bab.length(), "X");
			}
		}

		for (string bab : babbling) {
			size_t pos;
			for (; (pos = babblingInput[i].find(bab)) != string::npos;)
				babblingInput[i].replace(pos, bab.length(), "O");
		}

		bool flag = true;

		for (int j = 0; j < babblingInput[i].length(); j++) {
			if (babblingInput[i][j] != 'O') {
				flag = false;
				break;
			}
		}

		if (flag) {
			answer++;
		}
	}


	return answer;
}