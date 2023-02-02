class Solution {
    public int solution(int price) {
        if(price >= 500_000){
            return (int)(price *(double)80/100);
        }
        
        if(price >= 300_000){
            return (int)(price *(double)90/100);
        }
        
        if(price >= 100_000){
            return (int)(price *(double)95/100);
        }
        
        return price;
        
        
    }
}