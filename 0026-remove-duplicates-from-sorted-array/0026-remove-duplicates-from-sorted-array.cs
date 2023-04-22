public class Solution {
    public int RemoveDuplicates(int[] nums) {
        HashSet<int> s = new HashSet<int>();
        foreach(int i in nums)
            s.Add(i);
        int idx=0;
        foreach(int i in s)nums[idx++]=i;
        return s.Count;
    }
}