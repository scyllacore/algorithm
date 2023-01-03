#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    for(auto ptr=phone_number.begin(); ptr!=phone_number.end()-4; ptr++){ *ptr = '*';} 
    return phone_number;
}