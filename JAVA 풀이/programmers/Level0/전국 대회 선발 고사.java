import java.util.*;

class Solution {
    public int solution(int[] rank, boolean[] attendance) {
        List<Integer> students = new ArrayList<>();
        
        for(int i=0; i<rank.length; i++){
            if(attendance[i]){
                students.add(i);
            }
        }
        
        Collections.sort(students, new Comparator<Integer>(){
            @Override
            public int compare(Integer a,Integer b){
                return rank[a] - rank[b];
            }
        });
        
        return students.get(0) * 10000 + students.get(1) * 100 + students.get(2);
        
    }
}

/*
class Solution {
    public int solution(int[] rank, boolean[] attendance) {

        PriorityQueue<Integer> que = new PriorityQueue<>((a, b) -> rank[a] - rank[b]);
        for (int i = 0; i < attendance.length; i++) {
            if (attendance[i])
                que.add(i);
        }

        return que.poll() * 10000 + que.poll() * 100 + que.poll();
    }
}
*/

/*
class Solution {
    public int solution(int[] rank, boolean[] attendance) {
        return IntStream.range(0, rank.length)
                .filter(i -> attendance[i])
                .boxed()
                .sorted(Comparator.comparing(i -> rank[i]))
                .limit(3L)
                .reduce((current, next) -> current * 100 + next)
                .get();
    }
}
*/

/*
 Arrays.sort(student, (o1, o2) -> o1.rank - o2.rank);
*/