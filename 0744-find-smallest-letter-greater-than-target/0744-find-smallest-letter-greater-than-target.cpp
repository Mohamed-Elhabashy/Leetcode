class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans='z';
        bool flag=0;
        for(auto c:letters)
        {
            if(c>target){
                flag=1;
                ans=min(ans,c);
            }
        }
        return flag?ans:letters[0];
    }
};