#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int w, int num) {
        int answer = 0;

        vector<vector<int>> box(100, vector<int>(10,0));

        int y=0,x=0;
        int val = 1;

        for(;val<=n;){
                if(y%2 == 0){
                        box[y][x++] = val++;
                }else{
                        box[y][x--] = val++;
                }

                if(x > w-1){
                        --x,++y;
                }
                else if(x < 0){
                        ++x,++y;
                }
        }


        for(int i=0; i<n/w+1; i++){
                for(int j=0; j<w; j++){
                       if(box[i][j] == num){
                               y=i;
                               x=j;
                       }
                }
        }

        for(;;){
                if(box[y][x] == 0){
                        break;
                }
                y++;
                answer++;
        }
        return answer;
}

// w=1(x축 범위)일 경우, 가로(y축)이 100이 될 수 있기에 배열 공간 초기화 시, 가로를 100으로 둘 필요가 있다.

/*
class Solution {
    public int solution(int n, int w, int num) {
        int answer = 0;
        while (num <= n) {
            num += 2 * (w - ((num - 1) % w) - 1) + 1;
            answer ++;
        }
        return answer;
    }
}
*/
