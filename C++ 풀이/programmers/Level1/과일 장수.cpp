#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
	sort(score.begin(), score.end(), greater<>());

	int answer = 0;

	for (int i = 0; i + m - 1 < score.size(); i += m) {
		answer += score[i + m - 1] * m;
	}

	return answer;
}