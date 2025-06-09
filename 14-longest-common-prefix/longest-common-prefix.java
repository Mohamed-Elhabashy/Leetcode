class Solution {
    public String longestCommonPrefix(String[] strs) {
        String ans="";
        for(int i=0;i<strs[0].length();i++){
            char c=strs[0].charAt(i);
            boolean flag = true;
            for(int j=0;j<strs.length;j++){
                if(i>=strs[j].length() ||  strs[j].charAt(i)!=c){
                    flag=false;
                    break;
                }
            }
            if(flag)ans+=c;
            else break;
        }
        return ans;
    }
}