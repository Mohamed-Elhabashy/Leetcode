class Solution {
public:
    string s;
    vector<int> first = vector<int>(26, 100002);
    vector<int> last = vector<int>(26, -1);
    vector<int> right = vector<int>(100002, -1);
    pair<int,int> dp[100002];
    vector<string> ans;
    
    pair<int,int> solve(int i) {
        if (i >= s.size())
            return {0, 0};

        pair<int,int>& ret = dp[i];

        if (ret.first != -1)
            return ret;

        // Skip
        pair<int,int> ch1 = solve(i + 1);
        ret = ch1;

        // Take only if valid
        if (right[i] != -1) {

            int next = right[i] + 1;

            pair<int,int> ch2 = solve(next);

            ch2.first += 1;
            ch2.second += next - i;

            if (ch2.first > ch1.first)
                ret = ch2;

            else if (ch2.first == ch1.first &&
                    ch2.second < ch1.second)
                ret = ch2;
        }

        return ret;
    }
    void build(int i) {
        if (i >= s.size())
            return ;

        pair<int,int>& ret = dp[i];


        // Skip
        pair<int,int> ch1 = solve(i + 1);
        if(ret.first == ch1.first && ret.second == ch1.second){
            build(i+1);
            return ;
        }
        

        int next = right[i] + 1;

        pair<int,int> ch2 = solve(next);
        ans.push_back(s.substr(i, next - i));
        build(next);

        return ;
    }
    vector<string> maxNumOfSubstrings(string str) {
        s = str;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }


        for (int c = 0; c < 26; c++) {
            if (last[c] == -1) continue;

            int l = first[c];
            int r = last[c];
            bool valid = true;

            for (int j = l; j <= r; j++) {
                int ch = s[j] - 'a';

                if (first[ch] < l) {
                    valid = false;
                    break;
                }

                r = max(r, last[ch]);
            }

            if (valid)
                right[l] = r;
        }
        memset(dp,-1,sizeof dp);
        cout<<solve(0).first<<" " << solve(0).second<<endl;
        build(0);
        return ans;
    }   
};