class Solution {
public:
    int countbit(int x){
        int one=0;
        for(int i=0;i<30;i++)
            if(x&(1<<i))one++;
        return one;
    }
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++)
            ans.push_back(countbit(i));
        return ans;
    }
};