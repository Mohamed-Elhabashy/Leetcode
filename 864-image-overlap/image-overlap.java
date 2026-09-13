class Solution {
    int n;
    int solve(int x,int y,int[][] img1, int[][] img2){
        int cnt=0;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                int ni = i+x;
                int nj = j+y;
                if(ni>=0 && ni<n && nj>=0 && nj<n && img1[i][j]==1 && img2[ni][nj]==1)cnt++;
            }
        }
        return cnt;
    }
    public int largestOverlap(int[][] img1, int[][] img2) {
        int ans=0;
        n = img1.length;
        for (int x = -(n - 1); x <= n - 1; x++) {
            for (int y = -(n - 1); y <= n - 1; y++) {
                ans = Math.max(ans,solve(x,y,img1,img2));
            }
        }

        return ans;
    }
}