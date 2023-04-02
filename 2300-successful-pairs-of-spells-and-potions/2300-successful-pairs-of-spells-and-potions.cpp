class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int>ans;
        for(int i=0;i<spells.size();i++){
            int l=0,r=potions.size()-1,mid,idx=-1;
            while(l<=r){
                mid=(l+r)/2;
                if(1LL*spells[i]*potions[mid]>=success){
                    idx=mid;
                    r=mid-1;
                }
                else
                    l=mid+1;
            }
            ans.push_back(idx==-1?0:potions.size()-idx);
        }
        return ans;
    }
};