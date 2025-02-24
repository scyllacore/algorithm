#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
        int answer = -1;

        int h = park.size();
        for(int size : mats){
                for(int i=0; i<=h-size; i++){
                        int w = park[i].size();
                        for(int j=0; j<=w-size; j++){
                                if(park[i][j] != "-1"){
                                        continue;
                                }

                                bool isPossible = true;

                                for(int y=i; y<i+size; y++){
                                        for(int x=j; x<j+size; x++){
                                                if(park[y][x] != "-1"){
                                                        isPossible = false;
                                                        break;
                                                }
                                        }
                                }

                                if(isPossible){
                                        answer = max(answer, size);
                                        break;
                                }

                        }
                }
        }
    
    return answer;
}
