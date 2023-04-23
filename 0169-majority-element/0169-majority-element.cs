public class Solution {
    public int MajorityElement(int[] nums) {
        Dictionary < int,int > mp = new Dictionary < int,int > ();
        int ans=0,mx=0;
        foreach(int i in nums){
            if(mp.ContainsKey(i))mp[i]++;
            else mp[i]=1;
            if(mp[i]>mx)
            {
                mx=mp[i];
                ans=i;
            }
        }
        return ans;
    }
}