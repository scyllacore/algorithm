import java.util.ArrayList;
import java.util.List;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) {

        List<Integer> nums = new ArrayList<>(IntStream.iterate(1, i -> i < 20, i -> i + 2).boxed().toList());
        // stream은 int형으로 나오기 때문에 list로 만들기 위해서는 Wrapping 해야한다.

        System.out.println(get_binary_search_idx(nums,5));

    }

    private static int get_binary_search_idx(List<Integer> list,int target){
        int low = lower_bound(list,target);
        return (low < list.size() && list.get(low) == target) ? low : -1;
    }

    private static int lower_bound(List<Integer> list, int target){
        int low = 0;
        int high = list.size();
        int mid;

        for(;low<high;){
            mid = (low+high)/2;

            if(list.get(mid) < target){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        return low;
    }

}

