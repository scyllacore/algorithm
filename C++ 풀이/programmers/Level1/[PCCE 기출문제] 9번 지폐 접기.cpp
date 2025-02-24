#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;

    for(;;){
        int min_w,max_w;

        if(wallet[0] < wallet[1]){
                min_w = wallet[0];
                max_w = wallet[1];
        }
        else{
                min_w = wallet[1];
                max_w = wallet[0];
        }

        int min_b,max_b;

        if(bill[0] < bill[1]){
                min_b = bill[0];
                max_b = bill[1];
        }
        else{
                min_b = bill[1];
                max_b = bill[0];
        }
        
        //cout << min_b << ' ' << max_b << ' ' << min_w << ' ' << max_w << '\n';
        
        if(min_b <= min_w && max_b <= max_w){break;}

        if(bill[0] < bill[1]){
                bill[1] /= 2;
        }
        else{
                bill[0] /= 2;
        }

        answer++;
    }

    return answer;
}

