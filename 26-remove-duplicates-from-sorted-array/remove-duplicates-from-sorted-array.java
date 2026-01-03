class Solution {
    public int removeDuplicates(int[] nums) {
        boolean frq[] = new boolean[201];
        for(int x:nums)frq[x+100]=true;
        int idx=0;
        for(int i=0;i<=200;i++){
            if(frq[i]){
                nums[idx++]=i-100;
            }
        }
        return idx;
    }
}