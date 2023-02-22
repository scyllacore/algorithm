import java.util.*;
import java.util.stream.Collectors;

class Solution {
    public int[] solution(String today, String[] terms, String[] privacies) {
        String[] todayInfo = today.split("\\.");
        
        int todayVal = Integer.parseInt(todayInfo[0])*28*12 
            + Integer.parseInt(todayInfo[1])*28
            + Integer.parseInt(todayInfo[2]);
        
        Map<String , Integer> termMap = new HashMap<>();
        
        for(String term : terms){
            String[] termInfo = term.split(" ");
            termMap.put(termInfo[0],Integer.parseInt(termInfo[1]));
        }
        
        List<Integer> answer = new ArrayList<>();
        int n=0;
        
        for(String privacy :privacies){
            n++;
            String[] priDayInfo = privacy.substring(0,privacy.length()-2).split("\\.");
            
            String priTermInfo = privacy.substring(privacy.length()-1); 
            
            int priVal = Integer.parseInt(priDayInfo[0])*28*12 
            + Integer.parseInt(priDayInfo[1])*28
            + Integer.parseInt(priDayInfo[2]);
            
            priVal += termMap.get(priTermInfo) * 28;
            
            if(priVal <= todayVal){
                answer.add(n);
            }      
        }
        
       return answer.stream().mapToInt(i->i).toArray();
    }
}