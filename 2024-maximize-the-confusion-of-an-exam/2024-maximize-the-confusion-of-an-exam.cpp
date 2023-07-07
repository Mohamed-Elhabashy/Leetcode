class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int l=1,r=answerKey.size(),mid;
        while(l<r){
            mid=(l+r+1)/2;
            if(ok(mid,answerKey,k))l=mid;
            else r=mid-1;
        }
        return l;
    }
    bool ok(int len,string& answerKey, int k){
        map<char,int>mp;
        for(int i=0;i<len;i++)
            mp[answerKey[i]]++;
        if(min(mp['T'],mp['F'])<=k)return true;
        for(int i=len;i<answerKey.size();i++){
            mp[answerKey[i]]++;
            mp[answerKey[i-len]]--;
            if(min(mp['T'],mp['F'])<=k)return true;
        }
        return false;
    }
};