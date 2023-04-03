class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int ans=0,n=people.size();
        for(int i=0,j=n-1;i<=j;j--){
            if(people[j]+people[i]<=limit){
                i++;
                ans++;
            }
            else
                ans++;
        }
        return ans;
    }
};