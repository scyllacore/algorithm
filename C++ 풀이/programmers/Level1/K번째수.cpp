#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    
    int i;
    int size = commands.size();
    

    vector<int> answer;
    vector<int> tmp;
    
    for(i=0; i<size; i++){
        tmp.assign(array.begin()+commands[i][0]-1 , array.begin()+commands[i][1]);
        sort(tmp.begin(),tmp.end());    
        answer.push_back(tmp[commands[i][2]-1]);
        }
    
    
    return answer;
}

/*
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    
    int i;
    int size = commands.size();
    

    vector<int> answer;
    vector<int> tmp;
    
    for(i=0; i<size; i++){
        tmp.resize(commands[i][1] - commands[i][0] +1);
        copy(array.begin()+commands[i][0]-1 , array.begin()+commands[i][1],tmp.begin());
        sort(tmp.begin(),tmp.end());    
        answer.push_back(tmp[commands[i][2]-1]);
        }
    
    
    return answer;
}
*/