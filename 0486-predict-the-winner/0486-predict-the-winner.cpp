class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return solve(0,nums.size()-1,true,0,0,nums);
    }
    bool solve(int i,int j,bool turn ,int p1,int p2,vector<int>& nums){
        if(i>j){
            return p1>=p2;
        }
        if(turn){
            if(solve(i+1,j,false,p1+nums[i],p2,nums))return 1;
            if(solve(i,j-1,false,p1+nums[j],p2,nums))return 1;
            return 0;
        }
        
        if(!solve(i+1,j,true,p1,p2+nums[i],nums))return 0;
        if(!solve(i,j-1,true,p1,p2+nums[j],nums))return 0;
        return 1;
    }
};