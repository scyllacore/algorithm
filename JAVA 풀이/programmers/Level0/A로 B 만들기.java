class Solution {
    public int solution(String before, String after) {
        int[] beforeChecker = new int[26];
        int[] afterChecker = new int[26];

        for(int i=0; i<before.length(); i++){
            beforeChecker[before.charAt(i)-'a']++;
            afterChecker[after.charAt(i)-'a']++;
        }
        
        for(int i=0; i<26; i++){
            if(beforeChecker[i] != afterChecker[i]){
                return 0;
            }
        }
        
        return 1;
    }
}