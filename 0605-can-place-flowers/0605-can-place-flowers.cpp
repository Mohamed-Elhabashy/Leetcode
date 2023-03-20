class Solution {
public:
    bool canPlanted(int i,vector<int>& flowerbed){
        if(i-1>=0 && flowerbed[i-1]==1)return false;
        if(i+1<flowerbed.size() && flowerbed[i+1]==1)return false;
        if(flowerbed[i]==1)return false;
        return true;
    }
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i=0;i<flowerbed.size();i++){
            if(canPlanted(i,flowerbed)){
                n--;
                flowerbed[i]=1;
            }
        }
        return n<=0;
    }
};