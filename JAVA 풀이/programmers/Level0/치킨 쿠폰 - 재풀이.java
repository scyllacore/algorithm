class Solution {
    public int solution(int chicken) {
        int chickenCoupon=chicken;
        int serviceChicken=0;
        
        for(;chickenCoupon>9;){
            serviceChicken += (chickenCoupon/10);
            chickenCoupon = chickenCoupon/10+(chickenCoupon%10);
        }
        
        return serviceChicken;
        
    }
}