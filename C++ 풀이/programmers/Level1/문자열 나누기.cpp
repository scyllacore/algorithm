#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0;

	int same, diff;
	char start;

	for (int i = 0; i < s.size(); i++) {

		start = s[i];
		same = diff = 0;

		for (; i < s.size(); i++) {
			if (s[i] == start) {
				same++;
			}
			else {
				diff++;
			}

			if (same == diff) {
				break;
			}
		}
		answer++;
	}

	return answer;
}