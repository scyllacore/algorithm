#include <string>
#include <vector>
#include <queue>

using namespace std;

struct cmp {
	bool operator()(int& a, int& b) {
		return a > b;
	}

};

vector<int> solution(int k, vector<int> score) {
	priority_queue<int, vector<int>, cmp> pq;

	vector<int> answer;

	for (int val : score) {

		pq.push(val);
		if (pq.size() >= k + 1) {
			pq.pop();

		}

		/* ³Ö°í »©¾ßÇÔ
		if (pq.size() >= 3) {
			pq.pop();

		}
		pq.push(val);
		*/

		answer.push_back(pq.top());
	}

	return answer;
}