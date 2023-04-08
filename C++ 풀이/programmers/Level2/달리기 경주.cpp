#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {

    unordered_map<string, int> playerMap;

    for (int i = 0; i < players.size(); i++) {
        playerMap[players[i]] = i;
    }

    for (string calling : callings) {
        int curPlayer = playerMap[calling];
        int fastPlayer = curPlayer - 1;

        playerMap[players[curPlayer]]--;
        playerMap[players[fastPlayer]]++;

        swap(players[curPlayer], players[fastPlayer]);

        //여기서 값 설정하면 헷갈림
    }

    return players;
}

/*
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {

    unordered_map<string,int> playerMap;

    for(int i=0; i<players.size(); i++){
        playerMap[players[i]] = i;
    }

    for(string calling : callings){
        int fastPlayerIdx = playerMap[calling] - 1;
        string fastPlayer =  players[fastPlayerIdx];

        players[fastPlayerIdx] = players[fastPlayerIdx + 1];
        playerMap[calling] = fastPlayerIdx;

        playerMap[fastPlayer] = fastPlayerIdx + 1;
        players[fastPlayerIdx + 1] = fastPlayer;
    }

    return players;
}
*/