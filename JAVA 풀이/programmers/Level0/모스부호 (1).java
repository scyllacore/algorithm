import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collectors;


class Solution {

    public String[] mosArr = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    public Map<String, Character> mosMap = new HashMap<>();

    public String solution(String letter) {
        for (int i = 0; i < 26; i++) {
            mosMap.put(mosArr[i], (char) (i + 'a'));
        }
        return Arrays.stream(letter.split(" ")).map(this::getAlpha).collect(Collectors.joining());
    }

    public String getAlpha(String mos) {
        return mosMap.get(mos).toString();
    }

}