/*
안되는 코드 -> 조합으로 만들 수 있는 경우를 봐야한다.
int solution(vector<string> babblingInput) {
    string babbling[] = { "aya", "ye", "woo", "ma" };

	for (int i = 0; i < babblingInput.size(); i++) {
		for (string bab : babbling) {
            1.
			size_t pos;
			for (; (pos = babblingInput[i].find(bab)) != string::npos;) { // 괄호를 잘 쓰자.
				babblingInput[i].replace(pos, bab.length(), "");
			2.
            size_t pos = babblingInput[i].find(bab);
			if (pos != string::npos) {
				babblingInput[i].replace(pos, bab.length(), "");
			}
		}

	}

    int answer = 0;
    
	for (string input : babblingInput) {
		if (input.empty()) {
			answer++;
		}
	}
    
    return answer;
}


3. return을 안쓴 코드
#include <iostream>
#include <vector>

using namespace std;

string babbling[] = { "aya", "ye", "woo", "ma" };
vector<string> combiBabblings;
bool visited[4] = { false };

void makeCombi(int depth, string combiBabbling) {
	if (depth >= 4) {
		combiBabblings.push_back(combiBabbling);
	}

	for (int i = 0; i < 4; i++) {
		if (visited[i]) {
			continue;
		}

		visited[i] = true;
		makeCombi(depth + 1, combiBabbling + babbling[i]);
		visited[i] = false;

	}


}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string babbling[] = { "aya", "ye", "woo", "ma" };

	for (int i = 0; i < 4; i++) {
		makeCombi(i, "");
	}

	for (string combiBabbling : combiBabblings) {
		cout << combiBabbling << '\n';
	}


}


4. 될 것 같지만 안된 코드
#include <iostream>
#include <set>
#include <vector>

using namespace std;

string babbling[] = { "aya", "ye", "woo", "ma" };
set<string> combiBabblings;
bool visited[4] = { false };

void makeCombi(int depth, string combiBabbling) {
	if (depth >= 4) {
		combiBabblings.insert(combiBabbling);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (visited[i]) {
			continue;
		}

		visited[i] = true;
		makeCombi(depth + 1, combiBabbling + babbling[i]);
		visited[i] = false;

	}


}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string babbling[] = { "aya", "ye", "woo", "ma" };

	for (int i = 0; i < 4; i++) {
		makeCombi(i, "");
	}

	for (string combiBabbling : combiBabblings) {
		cout << combiBabbling << '\n';
	}

	vector<string> babblingInput = { "ayaye", "uuu", "yeye", "yemawoo", "ayaayaa" };

	int answer = 0;

	for (string input : babblingInput) {
		if (combiBabblings.find(input) != combiBabblings.end()) {
			answer++;
		}
	}

	return answer;

}

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<string> babbling = { "aya", "ye", "woo", "ma" };
	set<string> repeatedBabbling;

	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < 15; j++) {
			string str = "";
			for (int k = 0; k <= j; k++) {
				str += babbling[i];
			}
			repeatedBabbling.insert(str);
		}
	}

	/*for (string input : repeatedBabbling) {
		cout << input << '\n';
	}

	cout << '\n';*/


	vector<string> babblingInput = { "ayaye", "uuu", "yeye", "yemawoo", "ayaayaa" };

	for (int i = 0; i < babblingInput.size(); i++) {
		for (string bab : repeatedBabbling) {
			if ((babblingInput[i].find(bab)) != string::npos) {
				babblingInput[i] = "x";
			}
		}
	}


	for (int i = 0; i < babblingInput.size(); i++) {
		for (string bab : babbling) {
			size_t pos;
			for (; (pos = babblingInput[i].find(bab)) != string::npos;)
				babblingInput[i].replace(pos, bab.length(), "");
		}
	}

	int answer = 0;

	for (string input : babblingInput) {
		cout << input << '\n';
	}

	for (string input : babblingInput) {
		if (input.empty()) {
			answer++;
		}
	}

	cout << answer;

	return answer;

}


*/
