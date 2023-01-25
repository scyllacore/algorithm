class Solution {
    public String solution(String str) {
        String answer = "";
        
        int[] alphabetCount = new int[26];

        for(Integer i=0; i<str.length(); i++){
            alphabetCount[str.charAt(i)-'a']++;
        }

        for(Integer i=0; i<26; i++){
            if(alphabetCount[i] == 1){
                answer += String.format("%c",i+'a');
            }
        }
        
        return answer;
    }
}