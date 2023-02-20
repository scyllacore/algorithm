#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
	vector<int> v;

	int answer = 0;

	for (int i : ingredient) {

		v.push_back(i);

		for (;;) {
			int size = v.size();

			if (size < 4) {
				break;
			}

			if (!(v[size - 4] == 1 && v[size - 3] == 2 && v[size - 2] == 3 && v[size - 1] == 1)) {
				break;
			}

			v.erase(v.end() - 4, v.end());
			answer++;
		}

	}


	return answer;

}


/*
	string ingredientStr = "";

	for (int i : ingredient) {
		ingredientStr += to_string(i);
	}

	int answer = 0;

	size_t idx;
	for (; (idx = ingredientStr.find("1231")) != string::npos;) {
		ingredientStr = ingredientStr.substr(0, idx) + ingredientStr.substr(idx + 4);
		//ingredientStr.replace(idx, 4, "");
		answer++;
	}

	cout << answer;
	*/