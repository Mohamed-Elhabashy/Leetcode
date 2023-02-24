class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int>even;
        int mn=INT_MAX;
        for(auto x:nums){
            if(x&1){
                even.push(x*2);
                mn=min(mn,x*2);
            }
            else{
                even.push(x);
                mn=min(mn,x);
            }
        }
        int ans=INT_MAX;
        while(even.top()%2==0){
            int mx=even.top();
            ans=min(ans,mx-mn);
            even.pop();
            even.push(mx/2);
            mn=min(mn,mx/2); 
        }
        ans=min(ans,even.top()-mn);
        return ans;
    }
};