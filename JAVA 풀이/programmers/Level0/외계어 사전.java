class Solution {
    public int solution(String[] spell, String[] dic) {
        for(String word : dic){

            boolean checker = true;

            for(String spelling : spell){
                if(word.indexOf(spelling) == -1){
                    checker = false;
                    break;
                }
            }

            if(checker == true){
                return 1;
            }
        }
        return 2;

    }
}

/*
import java.util.HashSet;
import java.util.Set;

class Solution {
    
    public boolean[] visited = new boolean[26];
    public Set<String> combination = new HashSet<>();
    
    public int solution(String[] spell, String[] dic) {
        getCombination(0,spell,"");

        for(String word : dic){
            if(combination.contains(word)){
                return 1;
            }
        }
        return 2;
    }
    
    public void getCombination(int depth,String[] spell,String word){
        if(depth >= spell.length){
            combination.add(word);
        }

        for(int i=0; i<spell.length; i++){
            if(visited[i] == true){
                continue;
            }

            visited[i] = true;
            getCombination(depth+1,spell,word+spell[i]);
            visited[i] = false;
        }

    }
    
}
*/