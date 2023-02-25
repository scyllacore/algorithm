#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {

    unordered_map<char, int> minAlpha;

    for (int i = 'A'; i <= 'Z'; i++) {
        minAlpha[(char)i] = 999;
    }

    for (string key : keymap) {
        for (int i = 0; i < key.length(); i++) {
            if (i + 1 < minAlpha[key[i]]) {
                minAlpha[key[i]] = i + 1;
            }
        }
    }

    vector<int> answer;

    for (string target : targets) {

        int cnt = 0;

        for (char ch : target) {
            if (minAlpha[ch] == 999) {
                cnt = -1;
                break;
            }
            cnt += minAlpha[ch];
        }

        answer.push_back(cnt);

    }


    return answer;
}