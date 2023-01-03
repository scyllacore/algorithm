#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct musicInfo{
    int time;
    string name;
    string cutMusic;
    string music;
    int order;
};

bool cmp(const musicInfo& m1,const musicInfo& m2){
    if(m1.time == m2.time){
        return m1.order < m2.order;
    }
    else{
        return m1.time > m2.time;
    }
} 

string solution(string m, vector<string> musicinfos) {
    
    int mSize = musicinfos.size();
    vector<musicInfo> user(mSize);
    
    int i,j;
    for(i=0; i<mSize; i++){
        int sHour = stoi(musicinfos[i].substr(0,2));
        int sMinute = stoi(musicinfos[i].substr(3,2));
        int eHour = stoi(musicinfos[i].substr(6,2));
        int eMinute = stoi(musicinfos[i].substr(9,2));     
        user[i].time = (eHour*60+eMinute) - (sHour*60+sMinute);
        
        int pos = (musicinfos[i].substr(12)).find(',');   
        user[i].name = musicinfos[i].substr(12,pos);
        user[i].cutMusic = musicinfos[i].substr(12+(pos+1));
        
        user[i].order = i;  
    }
    
    for(i=0; i<mSize; i++){
        
        int idx=0;
        
        for(j=0; j<user[i].time; j++){
            if(user[i].cutMusic[idx] != '#'){
                user[i].music += user[i].cutMusic[idx];
                
                if(user[i].cutMusic[idx+1] == '#'){
                    user[i].music.back() += 32;
                    idx++;
                }
            }    
            idx++;       
            if(idx == user[i].cutMusic.size()){
                idx = 0;
            }       
        }       
    }
    
    sort(user.begin(),user.end(),cmp);
    
    string mTmp="";
    
    for(i=0; i<m.length(); i++){
        if(m[i] != '#'){
                mTmp += m[i];       
                if(m[i+1]== '#'){
                    mTmp.back() += 32;
                    i++;
                }
            }        
    }     
    
    m = mTmp;
    
    for(auto u : user){
        cout << u.music << '\n';
        if(u.music.find(m) != string::npos ){ // || m.find(u.music) != string::npos
           return u.name;
        }
    }
    
    return "(None)"; //이거 안써서 계속 오류남.
}

/*
cout << sHour <<' ' << sMinute << '\n';
cout << eHour <<' ' << eMinute << '\n';
cout << user[i].time << '\n';
cout << user[i].name << ' ' << user[i].music << '\n';
cout << user[i].music << '\n';
*/