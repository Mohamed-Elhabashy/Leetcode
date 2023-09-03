class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        set<int>st;
        map<int,int>mp;
        long long sum=0,ans=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
            st.insert(nums[i]);
            mp[nums[i]]++;
        }
        if(st.size()>=m)ans=sum;
        for(int i=0,j=k;j<nums.size();j++,i++){
            mp[nums[i]]--;
            mp[nums[j]]++;
            
            
            st.insert(nums[j]);
            sum-=nums[i];
            sum+=nums[j];
            if(mp[nums[i]]==0)st.erase(nums[i]);
            if(st.size()>=m){
                ans=max(ans,sum);
            }
        }
        return ans;
    }
};