import java.util.stream.IntStream;

class Solution {
    public int[] solution(int n, int[] slicer, int[] num_list) {
        if(n == 1){
            return IntStream.rangeClosed(0,slicer[1])
                .map(i -> num_list[i]).
                toArray();
        }else if(n == 2){
            return IntStream.range(slicer[0],num_list.length)
                .map(i -> num_list[i]).
                toArray();
        }
        else if(n == 3){
            return IntStream.rangeClosed(slicer[0],slicer[1])
                .map(i -> num_list[i]).
                toArray();
        }
        
        return IntStream.iterate(slicer[0], i -> i+slicer[2])
                .limit((slicer[1]-slicer[0] + slicer[2])/slicer[2]) // 이건 모르겠다.
                .map(i -> num_list[i])
                .toArray();
        
    }
}

//https://ryan-han.com/post/dev/java-stream/
//intstream of iterate