class Solution {
public:
    int countOdds(int low, int high) {
        int ans=(high+1)/2;
        ans-=(low+1)/2;
        ans+=(low%2==1);
        return ans;
    }
};