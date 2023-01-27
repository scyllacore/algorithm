class Solution {
    public String solution(String bin1, String bin2) {
        int decimal = changeBinaryToDecimal(bin1) + changeBinaryToDecimal(bin2);
        
        if(decimal == 0) {
            return "0";
        }
        
        return changeDecimalToBinary(decimal);
    }
    
    public int changeBinaryToDecimal(String binary){
        int decimal = 0;

        for(int i=0; i<binary.length(); i++){
            decimal = decimal * 2 + (int)binary.charAt(i)-'0';
        }

        return decimal;
    }

    public String changeDecimalToBinary(int decimal){
        String binary = "";

        for(;decimal>0;){
            binary += decimal%2 == 1 ? "1" : "0";
            decimal/=2;
        }
        
        StringBuffer sb = new StringBuffer(binary);
        return sb.reverse().toString();
    }
    
}