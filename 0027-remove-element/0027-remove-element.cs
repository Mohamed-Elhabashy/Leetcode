public class Solution {
    public int RemoveElement(int[] nums, int val) {
        var v = new ArrayList();
        int idx=0;
        foreach(int i in nums){
            if(i!=val)v.Insert(idx++,i);
        }
        for(int i=0;i<v.Count;i++)
            nums[i]=(int)v[i];
        return v.Count;
    }
}