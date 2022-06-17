class Solution {
    public int mySqrt(int x) {
        if (x < 2) return x;
        int rootMin = 2, rootMax = x/2;
        while (rootMin <= rootMax) {
            int rootMid = rootMin + (rootMax - rootMin) / 2;
            long square = (long)Math.pow(rootMid, 2);
            if (square == (long)x) {
                return rootMid;
            }
            if (square > (long)x){
                rootMax = rootMid -1;
            } else {
                rootMin = rootMid + 1;
            }
        }
        return rootMax;
    }
}
