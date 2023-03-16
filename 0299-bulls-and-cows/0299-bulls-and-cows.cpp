class Solution {
public:
    string getHint(string secret, string guess) {
        int x=0;
        int sz=secret.size();
        vector<int>frq1(10),frq2(10);
        for(int i=0;i<sz;i++){
            if(secret[i]==guess[i])x++;
            else {
                frq1[secret[i]-'0']++;
                frq2[guess[i]-'0']++;
            }
        }
        int y=0;
        for(int i=0;i<10;i++){
            y+=min(frq1[i],frq2[i]);
        }
        return to_string(x)+"A"+to_string(y)+"B";
    }
};