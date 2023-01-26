import java.util.HashMap;
import java.util.Map;

class Solution {
    public String solution(String[] id_pw, String[][] db) {
        Map<String,String> dbTable = new HashMap<>();

        for(int i=0; i<db.length; i++){
            dbTable.put(db[i][0],db[i][1]);
        }

        if(dbTable.containsKey(id_pw[0])){

            if(dbTable.get(id_pw[0]).equals(id_pw[1])){
                return "login";
            }

            return "wrong pw";
        }

        return "fail";

    }
}