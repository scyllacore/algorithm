#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    unordered_set<int> nSet;

    int size = elements.size();

    for (int i = 0; i < size; i++) {

        int sum = 0;

        for (int j = i; j < i + size; j++) {
            sum += elements[j % size];
            nSet.insert(sum);
        }
    }

    return nSet.size();

}

/*
#include <string>
#include <vector>
#include <unordered_set>
#include <deque>

using namespace std;

int solution(vector<int> elements) {
    int size = elements.size();

    unordered_set<int> nSet;
    deque<int> sequence;

    for(int e : elements){
        sequence.push_back(e);
    }

    for(int len=1; len<=size; len++){
        for(int i=1; i<=size; i++){

            int sum=0;

            for(int j=0; j<len; j++){
                sum += sequence[j];
            }

            nSet.insert(sum);

            sequence.push_back(sequence.front());
            sequence.pop_front();

        }
    }

    return nSet.size();
}
*/