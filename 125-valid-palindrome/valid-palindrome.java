class Solution {
    public boolean isPalindrome(String s) {
        s = s.replaceAll("[^a-zA-Z0-9]", "").toLowerCase();
        String reversed = new StringBuilder(s).reverse().toString();
        System.out.println(s);
        System.out.println(reversed);
        return s.equals(reversed);
    }
}