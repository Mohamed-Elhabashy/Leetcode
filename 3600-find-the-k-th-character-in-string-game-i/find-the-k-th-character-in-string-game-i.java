class Solution {
    public char kthCharacter(int k) {
        StringBuilder str  = new StringBuilder("a");
        while(str.length()<k)
        {
            int sz=str.length();
            for(int i=0;i<sz;i++){
                char c= str.charAt(i)=='z'?'a':(char) (str.charAt(i) + 1);
                str.append(c);
            }
        }
        return str.charAt(k-1);
    }
}
