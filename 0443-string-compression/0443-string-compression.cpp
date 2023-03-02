class Solution {
public:
    int compress(vector<char>& chars) {
        chars.push_back('-');
        char c=chars[0];
        int idx=0,cnt=1;
        for(int i=1;i<chars.size();i++){
            if(chars[i]==c){
                cnt++;
            }
            else{
                if(cnt!=1){
                    chars[idx]=c;
                    string counter=to_string(cnt);
                    for(auto x:counter){
                        chars[++idx]=x;
                    }
                    idx++;
                    //cout<<c<<" "<<cnt<< " "<<idx<<endl;
                    c=chars[i];
                    cnt=1;
                }
                else{
                    chars[idx]=c;
                    idx++;
                    c=chars[i];
                    cnt=1;
                }
            }
        }
        return idx;
    }
};