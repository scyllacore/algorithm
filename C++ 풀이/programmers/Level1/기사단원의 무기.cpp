#include <string>
#include <vector>

using namespace std;

int getDivisorCnt(int n) {

	int cnt = 0;

	for (int i = 1; i <= n / i; i++) {

		if (n % i == 0) {
			cnt++;

			if (n / i != i) {
				cnt++;
			}

		}

	}

	return cnt;
}

int solution(int number, int limit, int power) {
	int answer = 0;

	for (int i = 1; i <= number; i++) {

		int cnt = getDivisorCnt(i);

		if (cnt > limit) {
			answer += power;
		}
		else {
			answer += cnt;
		}
	}

	return answer;
}