class FindSumPairs {
    int[] nums1= new int[1001];
    int[] nums2= new int[100001];
    Map<Integer,Integer> mp = new HashMap<>();
    public FindSumPairs(int[] nums1, int[] nums2) {
        this.nums1=nums1;
        this.nums2=nums2;
        for (int i = 0; i < nums2.length; i++) {
            int num = nums2[i];
            mp.put(num, mp.getOrDefault(num, 0) + 1);
        }
    }

    public void add(int index, int val) {
        int old = this.nums2[index];
        mp.put(old, mp.getOrDefault(old, 0) - 1);
        this.nums2[index]+=val;
        mp.put(this.nums2[index], mp.getOrDefault(this.nums2[index], 0) + 1);

    }

    public int count(int tot) {
        int count=0;
        for(int j=0;j<this.nums1.length;j++){
            int rem=tot-this.nums1[j];
            if(mp.containsKey(rem))count+=mp.get(rem);
        }
        return count;
    }
}

