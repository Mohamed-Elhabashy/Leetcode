class Solution {
    public String clearStars(String s) {
        char[] chars = s.toCharArray();

        Map<Character, List<Integer>>mp = new HashMap<>();
        for(int i=0;i<chars.length;i++){
            if(chars[i]=='*'){
                for(char x='a';x<='z';x++){
                    if(!mp.containsKey(x) || mp.get(x).isEmpty())continue;
                    int lastIndexInList = mp.get(x).size() - 1;
                    int postionOfChar =  mp.get(x).get(lastIndexInList);
                    mp.get(x).remove(lastIndexInList);
                    chars[postionOfChar]='A';
                    break;
                }
            }
            else{
                mp.putIfAbsent(chars[i],new ArrayList<>());
                mp.get(chars[i]).add(i);

            }
        }
        String ans="";
        for(int i=0;i<chars.length;i++){
            if(chars[i]=='A' || chars[i]=='*')continue;
            ans+=chars[i];
        }
        return ans;
    }
}