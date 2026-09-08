class Solution {
    public int countCommas(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            int len = String.valueOf(i).length();
            ans += (len/3) - (len%3==0?1:0);
        }
        return ans;
    }
}