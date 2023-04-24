import java.util.*;

class Solution {
    public String[] solution(String[] picture, int k) {
        List<String> zoomPic = new ArrayList<>();

        for(int i=0; i< picture.length; i++){

            StringBuffer line = new StringBuffer();

            for(int j=0; j<picture[i].length(); j++){
                line.append(String.format("%c",picture[i].charAt(j)).repeat(k));
            }

            for(int j=0; j<k; j++){
                zoomPic.add(line.toString());
            }
        }

        return zoomPic.toArray(String[]::new);
    }
}

// https://ifuwanna.tistory.com/355