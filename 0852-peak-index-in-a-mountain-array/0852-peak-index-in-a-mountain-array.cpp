class Solution {
public:
    int ok(int i,vector<int>&arr){
        if(i==0)return 1;
        if(i==arr.size()-1)return -1;
        if(arr[i]>arr[i+1] && arr[i]>arr[i-1])return 0;
        if(arr[i]>arr[i+1] && arr[i]<arr[i-1])return -1;
        return 1;
        
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0,r=arr.size()-1,mid;
        while(l<=r){
            mid=(l+r)/2;
            if(ok(mid,arr)==0)return mid;
            else if(ok(mid,arr)==1)l=mid+1;
            else r=mid-1;
        }
        return -1;
    }
};