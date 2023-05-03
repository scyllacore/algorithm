class Solution {
    public int solution(int[] num_list) {
        StringBuffer odd = new StringBuffer();
        StringBuffer even = new StringBuffer();
        
        for(int num : num_list){
            if(num%2 == 1){
                odd.append(num);
            }else{
                even.append(num);
            }
        }
        
        return Integer.parseInt(odd.toString()) +  Integer.parseInt(even.toString());   
    }
}