class Solution {
    public int solution(int[] num_list) {
        int mulVal=1;
        int powVal=0;
        
        for(int num : num_list){
            mulVal *= num;
            powVal += num;
        }
        
        return mulVal < (int)Math.pow(powVal,2) ? 1 : 0;
    }
}