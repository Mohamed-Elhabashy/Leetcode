class Solution {
    public int possibleStringCount(String word) {

        int ans=1;
        for(int i=0;i<word.length();){
            int count=1;
            i++;
            while(i<word.length() && word.charAt(i)==word.charAt(i-1)){
                count++;
                i++;
            }
            ans+=count-1;
        }
        return ans;
    }
}