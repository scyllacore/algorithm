import java.util.*;

class Solution {
    public Set<String> babblingCombination = new HashSet<>();
    public List<Boolean> checker = new ArrayList<>(Collections.nCopies(4, false));
    public List<String> babblingList = new ArrayList<>(
            List.of("aya", "ye", "woo", "ma")
    );

    private void createBabblingCombination(String babbling, Integer depth) {
        if (depth >= 4) {
            babblingCombination.add(babbling);
            return;
        }

        for (Integer i = 0; i < 4; i++) {
            if (checker.get(i)) {
                continue;
            }

            checker.set(i, true);
            createBabblingCombination(babbling + babblingList.get(i), depth + 1);
            checker.set(i, false);
        }
    }


    public int solution(String[] babbling) {
        int answer = 0;

        for(Integer startDepth=0; startDepth<4; startDepth++) {
            createBabblingCombination("", startDepth);
        }

	/*for(String str : babblingCombination){
            System.out.printf("%s\n",str);
        }*/

        for (Integer i = 0; i < babbling.length; i++) {
            if (babblingCombination.contains(babbling[i])) {
                answer++;
            }
        }

        return answer;
    }
}

//class Solution {
//    public int solution(String[] babbling) {
//        int answer = 0;
//        for(int i=0; i<babbling.length; i++){
//            if(babbling[i].matches("^(aya(?!aya)|ye(?!ye)|woo(?!woo)|ma(?!ma))+$")){
//                answer++;
//            }
//        }
//        return answer;
//    }
//}

//class Solution {
//    public int solution(String[] babbling) {
//        int answer = 0;
//
//        for(int i =0; i < babbling.length; i++) {
//            babbling[i] = babbling[i].replace("aya", "1");
//            babbling[i] = babbling[i].replace("woo", "1");
//            babbling[i] = babbling[i].replace("ye", "1");
//            babbling[i] = babbling[i].replace("ma", "1");
//            babbling[i] = babbling[i].replace("1", "");
//            if(babbling[i].isEmpty()) {
//                answer = answer + 1;
//            }
//        }
//
//        return answer;
//    }
//}