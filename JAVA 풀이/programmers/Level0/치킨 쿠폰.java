class Solution {
    public int solution(int chickenCoupon) {
        int serviceChicken = 0;

        for (; chickenCoupon / 10 > 0; ) {
            serviceChicken += chickenCoupon / 10;
            chickenCoupon = chickenCoupon / 10 + chickenCoupon % 10;
        }

        return serviceChicken;
    }
}

// 치 1081
// 쿠 1081 -> 1 
// 서치 108 + 쿠 1
// 쿠 108 + 쿠 1 = 쿠 109 -> 2
// 서치 10 + 쿠 9
// 쿠 10 + 쿠 9 = 쿠 19 -> 3
// 서치 1 + 쿠 9
// 쿠 1 + 쿠 9 = 쿠 10 -> 4
// 서치 1
// 쿠 1 -> 5 (조건 X)