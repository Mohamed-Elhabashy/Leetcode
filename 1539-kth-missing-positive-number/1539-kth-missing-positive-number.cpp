class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int counter=1,idx=0;
        while(idx<arr.size()){
            if(arr[idx]==counter)counter++,idx++;
            else{
                k--;
                if(k==0)return counter;
                counter++;
            }
        }
        return counter+k-1;
    }
};