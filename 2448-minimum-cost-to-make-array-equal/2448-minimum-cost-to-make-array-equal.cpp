class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<int,int>>num;
        for(int i=0;i<nums.size();i++){
            num.push_back({nums[i],cost[i]});
        }
        sort(num.begin(),num.end());
        for(int i=0;i<nums.size();i++){
            nums[i]=num[i].first;
            cost[i]=num[i].second;
        }
        vector<long long>cm(nums.size());
        cm[0]=cost[0];
        for(int i=1;i<nums.size();i++)
            cm[i]=cm[i-1]+cost[i];
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            int dif=nums[i]-nums[0];
            sum+=(1LL*dif*cost[i]);
        }
        long long ans=sum;
        cout<<sum<<endl;
        for(int i=1;i<nums.size();i++){
            int dif=nums[i]-nums[i-1];
            sum-=1ll*(cm[nums.size()-1]-cm[i-1])*dif;
            
            sum+=1ll*cm[i-1]*dif;
            
            ans=min(ans,sum);
        }
        return ans;
    }
};