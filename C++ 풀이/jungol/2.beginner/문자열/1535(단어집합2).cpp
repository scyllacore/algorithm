#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {

	unordered_map<string, bool> um;
	string str;

	vector<string> words;

	for (;;) {
		getline(cin, str);

		if (str == "END") {
			break;
		}

		istringstream iss(str);

		string word;
		for (; iss >> word;) {
			if(!um[word]){
				words.push_back(word);
				um[word] = 1;
			}
		}

		for (auto outWord : words) {
			cout << outWord << ' ';
		}

		cout << '\n';

	}


}