#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    unordered_map<string, int> partSet;

    int size = participant.size();
    int i;

    for (i = 0; i < size; i++) {
        partSet[participant[i]]++;
    }

    size = completion.size();

    for (i = 0; i < size; i++) {
        if (partSet[completion[i]] == 1) {
            partSet.erase(completion[i]);
        }
        else if (partSet[completion[i]] > 1) {
            partSet[completion[i]]--;
        }
    }

    string answer = "";

    for (auto ptr : partSet) {
        return ptr.first;
    }


    return answer;
}

/*
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    unordered_map<string,int> partSet;

    int size = participant.size();
    int i;

    for(i=0; i<size; i++){
        partSet[participant[i]]++;
    }

    size = completion.size();

    for(i=0; i<size; i++){
          partSet[completion[i]]--;
    }

     string answer = "";

    for(auto ptr : partSet){
        if(ptr.second != 0){
            answer = (ptr.first);
            break;
        }
    }


    return answer;
}


#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    unordered_map<string,int> partSet;

    int size = participant.size();
    int i;

    for(i=0; i<size; i++){
        if(partSet.find(participant[i]) == partSet.end()){
            partSet.insert({participant[i],1});
        }
        else{
          partSet[participant[i]]++;
        }

    }

    size = completion.size();

    for(i=0; i<size; i++){
        if(partSet.find(completion[i]) != partSet.end()){
          partSet[completion[i]]--;
        }
    }

     string answer = "";

    for(auto ptr = partSet.begin(); ptr != partSet.end(); ptr++){ // auto ptr:partSet
        if(ptr->second != 0){ // ptr.second
            answer += (ptr->first); // ptr.first
            break;
        }
    }


    return answer;
}
*/