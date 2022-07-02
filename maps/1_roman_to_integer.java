class Solution {
    public int romanToInt(String s) {
        if (s == null || s == "") return 0;
        HashMap<Character, Integer> mp = new HashMap<>();
        mp.put('I', 1);
        mp.put('V', 5);
        mp.put('X', 10);
        mp.put('L', 50);
        mp.put('C', 100);
        mp.put('D', 500);
        mp.put('M', 1000);
        int result = 0;
        for (int i = 1; i <= s.length(); i++) {
            if (i != s.length() && mp.get(s.charAt(i)) > mp.get(s.charAt(i-1))) {
                result += mp.get(s.charAt(i)) - mp.get(s.charAt(i-1));
                i++;
            } else {
                result += mp.get(s.charAt(i-1));
            }
        }
        return result;
    }
}
