class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        
        vector<vector<int>> arr(n, vector<int>(n));
        for(auto q:queries){
            int x1=q[0],y1=q[1];
            int x2=q[2],y2=q[3];
            for(int i=x1;i<=x2;i++){
                arr[i][y1]++;
                if(y2+1<n)
                    arr[i][y2+1]--;
            }
        }
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum+=arr[i][j];
                arr[i][j]=sum;
            }
        }
        return arr;

    }
};