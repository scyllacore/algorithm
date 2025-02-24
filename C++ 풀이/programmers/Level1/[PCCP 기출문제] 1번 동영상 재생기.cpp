#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

int get_time(string& t){
    istringstream iss(t);
    int hour, minute;
    char delimiter;
    
    iss >> hour >> delimiter >> minute;
    
    return hour * 60 + minute;
}

string get_time_str(int t) {
    int hour = t / 60;
    int minute = t % 60;

    std::ostringstream oss;
    oss << setw(2) << setfill('0') << hour << ":"
        << setw(2) << setfill('0') << minute;

    return oss.str();
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int vl = get_time(video_len);
    int p = get_time(pos);
    int os = get_time(op_start);
    int oe = get_time(op_end);
    
    for(string cmd : commands){
        if(p >= os && p <= oe){
            p = oe;
        }
        
        if(cmd[0] == 'p'){
            p -= 10; 
        }else{
            p += 10;
        }
        
        if(p < 0){
            p = 0;
        }
        else if(p > vl){
            p = vl;
        }
        
    }
    
    if(p >= os && p <= oe){
        p = oe;
    }
    
    return get_time_str(p);
}
