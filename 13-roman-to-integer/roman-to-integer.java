
class Solution {
    public int romanToInt(String s) {
        HashMap<Character,Integer> mp = new HashMap<>();
        mp.put('I',1);
        mp.put('V',5);
        mp.put('X',10);
        mp.put('L',50);
        mp.put('C',100);
        mp.put('D',500);
        mp.put('M',1000);
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(i+1 < s.length() &&s.charAt(i)=='I' && s.charAt(i+1)=='V' ){
                ans+=4;
                i++;
            }
            else if(i+1 < s.length() &&s.charAt(i)=='I' && s.charAt(i+1)=='X' ){
                ans+=9;
                i++;
            }
            else if(i+1 < s.length() &&s.charAt(i)=='X' && s.charAt(i+1)=='L' ){
                ans+=40;
                i++;
            }
            else if(i+1 < s.length() &&s.charAt(i)=='X' && s.charAt(i+1)=='C' ){
                ans+=90;
                i++;
            }
            else if(i+1 < s.length() &&s.charAt(i)=='C' && s.charAt(i+1)=='D' ){
                ans+=400;
                i++;
            }
            else if(i+1 < s.length() &&s.charAt(i)=='C' && s.charAt(i+1)=='M' ){
                ans+=900;
                i++;
            }
            else
                ans+=mp.get(s.charAt(i));
        }
        return ans;
    }
}