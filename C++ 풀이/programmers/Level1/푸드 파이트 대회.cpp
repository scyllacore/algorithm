#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
	ostringstream oss;

	for (int i = 1; i < food.size(); i++) {
		for (int j = 0; j < food[i] / 2; j++) {
			oss << i;
		}
	}

	string left, right;
	left = right = oss.str();

	reverse(right.begin(), right.end());

	return left + "0" + right;
}