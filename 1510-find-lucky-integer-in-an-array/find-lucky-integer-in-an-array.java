class Solution {
    public int findLucky(int[] arr) {
        int frq[]=new int[501];
        for (int i=0;i<arr.length;i++){
            frq[arr[i]]++;
        }
        for(int i=500;i>=1;i--){
            if(frq[i]==i)return i;
        }
        return -1;
    }
}