public class Solution {
    public int MaxProfit(int[] prices) {
        int ans=0,mn=int.MaxValue;
        foreach(var num in prices){
            mn=Math.Min(num,mn);
            ans=Math.Max(ans,num-mn);
        }
        return ans;
    }
}