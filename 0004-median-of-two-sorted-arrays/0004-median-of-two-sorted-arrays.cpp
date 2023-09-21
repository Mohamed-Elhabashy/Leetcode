class Solution {
public:
    vector<int>v;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(auto x:nums1)v.push_back(x);
        for(auto x:nums2)v.push_back(x);
        sort(v.begin(),v.end());
        if(v.size()&1)
            return v[v.size()/2];
        return (v[v.size()/2]+v[v.size()/2-1])/2.0;
    }
};