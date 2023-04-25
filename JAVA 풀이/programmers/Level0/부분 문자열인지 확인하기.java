#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string my_string, string target) {
    return my_string.find(target) != string::npos ? 1 : 0;
}

//find(my_string.begin(),my_string.end(),target) != my_string.end() ? 1 : 0; 부분이 아니고 여러 원소 중에 하나를 찾아주는 역할을 해준다.