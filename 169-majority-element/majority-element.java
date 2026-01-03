class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        int cnt=0,i;
        for(i=0;i<nums.length;i++){
            if(i==0 || nums[i]!=nums[i-1]){
                cnt=1;
                continue;
            }
            cnt++;
            if(cnt>(nums.length/2))return nums[i];
        }
        return nums[i-1];
    }
}