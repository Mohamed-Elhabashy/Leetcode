class Solution {
public:
    int DifX(vector<int>&a,vector<int>&b){
        return a[0]-b[0];
    }
    
    int DifY(vector<int>&a,vector<int>&b){
        return a[1]-b[1];
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int difX=DifX(coordinates[1],coordinates[0]);
        int difY=DifY(coordinates[1],coordinates[0]);
        for(int i=2;i<coordinates.size();i++){
            int x=DifX(coordinates[i],coordinates[0]);
            int y=DifY(coordinates[i],coordinates[0]);
            if(difX*y!=difY*x){
                return 0;
            }
        }
        return 1;
    }
};