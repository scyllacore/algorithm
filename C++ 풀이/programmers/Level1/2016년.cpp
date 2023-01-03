#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    
    int month[12]= {31,29,31,30,31,30,31,31,30,31,30,31};
    
    int dDay = b-1,i;//1월 1일을 D day 1이 아닌 0으로 지정해둔다.
    
    for(i=0; i<a-1; i++){
        dDay += month[i];
    }
    
    string week[7] = {"FRI","SAT","SUN","MON","TUE","WED","THU"}; 
    
    string answer = week[dDay%7];
    return answer;
}