class Solution {
public:
    unordered_map<int,int>mp;
    long long putMarbles(vector<int>& weights, int k) {
        long long mn=0,mx=0;
        vector<int>v;
        
        for(int i=1;i<weights.size();i++){
            v.push_back(weights[i]+weights[i-1]);
        }
        sort(v.rbegin(),v.rend());
        for(int i=0,j=v.size()-1;i<k-1;i++,j--){
            mx+=v[i];
            mn+=v[j];
        }
        return mx-mn;
    }
};