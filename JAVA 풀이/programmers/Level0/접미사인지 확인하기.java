class Solution {
    public int solution(String my_string, String is_suffix) {
        int idx = my_string.lastIndexOf(is_suffix);
        
        return idx != -1 && idx == my_string.length() - is_suffix.length() ? 1 : 0;
    }
}

// my_string.endsWith(is_suffix); startsWith