class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int>row;
        int n=grid.size();
        for(int i=0;i<n;i++){
            row[grid[i]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int>tmp;
            for(int j=0;j<n;j++){
                tmp.push_back(grid[j][i]);
            }
            ans+=row[tmp];
        }
        return ans;
    }
};