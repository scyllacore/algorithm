#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string new_id) {
    
    int i,j;
    
    string tmp1;
    
    //1,2
    for(i=0; i<new_id.length(); i++){
        if(islower(new_id[i])){
            tmp1 += new_id[i];
        }
         else if(isupper(new_id[i])){
            tmp1 += tolower(new_id[i]);
        }
        else if(isdigit(new_id[i])){
            tmp1 += new_id[i];
        }
        else if(new_id[i] =='-' || new_id[i] =='_' || new_id[i] =='.'){
            tmp1 += new_id[i];
        }
       

    }
    
    
    //3
    string tmp2;
    
    for(i=0; i<tmp1.length(); i++){
        tmp2 += tmp1[i];
        if(tmp1[i] == '.'){
            for(j=i+1; tmp1[j]=='.'; j++);
            i = j-1;
        }     
    }
    
    //4
    if(tmp2[0] == '.'){tmp2.erase(tmp2.begin());}
    if(tmp2.back() == '.'){tmp2.pop_back();}
    
    
    //5
    int tmp2Len =tmp2.length();
    if(tmp2Len==0){
        tmp2+='a';
    }
    
    //6
    tmp2Len =tmp2.length();
    
    if(tmp2Len>15){
        tmp2.erase(tmp2.begin()+15,tmp2.end());
    }
    
    if(tmp2.back() == '.'){tmp2.erase(tmp2.end()-1);}
    
    
    //7
    tmp2Len =tmp2.length();
    if(tmp2Len==2){
        tmp2+= tmp2[1];
    }
    else if(tmp2Len==1){
        tmp2+= tmp2[0];
        tmp2+= tmp2[0]; 
    }
    
    
    string answer = tmp2;
    return answer;
}

/*
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    
    int i,j;
    
    string tmp1;
    
    //1,2
    for(i=0; i<new_id.length(); i++){
        if(new_id[i]>='a' && new_id[i] <= 'z'){
            tmp1 += new_id[i];
        }
         else if(new_id[i]>='A' && new_id[i] <= 'Z'){
            tmp1 += (new_id[i]+32);
        }
        else if(new_id[i]>='0' && new_id[i] <= '9'){
            tmp1 += new_id[i];
        }
        else if( new_id[i] =='-' || new_id[i] =='_' || new_id[i] =='.'){
            tmp1 += new_id[i];
        }
       

    }
    
    
    //3
    string tmp2;
    
    for(i=0; i<tmp1.length(); i++){
        tmp2 += tmp1[i];
        if(tmp1[i] == '.'){
            for(j=i+1; tmp1[j]=='.'; j++){}
            i = j-1;
        }     
    }
    
    //4
    if(tmp2[0] == '.'){tmp2.erase(tmp2.begin());}
    int tmp2Len =tmp2.length();
    if(tmp2[tmp2Len-1] == '.'){tmp2.erase(tmp2.begin()+tmp2Len-1);}
    
    
    //5
    tmp2Len =tmp2.length();
    if(tmp2Len==0){
        tmp2+='a';
    }
    
    //6
    tmp2Len =tmp2.length();
    
    if(tmp2Len>15){
        tmp2.erase(tmp2.begin()+15,tmp2.end());
    }
    
    tmp2Len =tmp2.length();
    if(tmp2[tmp2Len-1] == '.'){tmp2.erase(tmp2.begin()+tmp2Len-1);}
    
    
    //7
    tmp2Len =tmp2.length();
    if(tmp2Len==2){
        tmp2+= tmp2[1];
    }
    else if(tmp2Len==1){
        tmp2+= tmp2[0];
        tmp2+= tmp2[0]; 
    }
    
    
    string answer = tmp2;
    return answer;
}
*/