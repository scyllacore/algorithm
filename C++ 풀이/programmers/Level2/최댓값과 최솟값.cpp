#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string s) {
    
    vector<long long> num;
    
    istringstream iss(s);
    
    string tmp ="";     
    for(;iss >> tmp;){
        num.push_back(stoi(tmp));
    }
    
    long long maxVal = *max_element(num.begin(),num.end());
    long long minVal = *min_element(num.begin(),num.end()); 
      
    string answer = to_string(minVal) + " " + to_string(maxVal);
    return answer;
}

/*

   string token;

   while(getline(iss, token, ' '))
    {
          num.push_back(stoi(token));
    }
*/