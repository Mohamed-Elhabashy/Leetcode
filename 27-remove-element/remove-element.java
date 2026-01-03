class Solution {
    public int removeElement(int[] nums, int val) {
        int ans=0;
        int index=0;
        for(int x:nums){
            if(x != val){
                ans++;
                nums[index++]=x;
            }
        }
        return ans;
    }
}