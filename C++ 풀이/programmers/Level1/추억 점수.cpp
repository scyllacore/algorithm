#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;

    unordered_map<string, int> scoreInfo;

    int size = name.size();

    for (int i = 0; i < size; i++) {
        scoreInfo[name[i]] = yearning[i];
    }

    for (vector<string> pic : photo) {
        int sum = 0;

        for (string person : pic) {
            sum += scoreInfo[person];
        }

        answer.push_back(sum);
    }

    return answer;
}