#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    int size = numbers.size();
    vector<int> answer(size, -1);

    vector<int> overNumbers;

    for (int i = size - 1; i >= 0; i--) {

        for (; !overNumbers.empty() && numbers[i] >= overNumbers.back();) {
            overNumbers.pop_back();
        }

        if (!overNumbers.empty()) {
            answer[i] = overNumbers.back();
        }

        overNumbers.push_back(numbers[i]);
    }


    return answer;
}