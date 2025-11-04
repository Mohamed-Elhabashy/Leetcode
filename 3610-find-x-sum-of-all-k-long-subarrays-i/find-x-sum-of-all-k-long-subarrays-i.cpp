class Solution {
public:
    int solve(vector<pair<int,int>> frq,int x){
        sort(frq.begin(), frq.end(), [](pair<int,int> &a, pair<int,int> &b) {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first > b.first;
        });
        int sum=0;
        for(int i=0;i<x;i++){
            int a=frq[i].first;
            int b=frq[i].second;
            sum+=(a*b);
        }
        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int>ans;
        vector<pair<int, int>> frq(51, {0, 0});
        for(int i=0;i<k;i++){
            frq[nums[i]].first++;
            frq[nums[i]].second=nums[i];
        }
        ans.push_back(solve(frq,x));
        for(int i=0,j=k;j<nums.size();i++,j++){
            frq[nums[i]].first--;
            
            frq[nums[j]].first++;
            frq[nums[j]].second=nums[j];
            
            ans.push_back(solve(frq,x));

        }
        return ans;
    }
};