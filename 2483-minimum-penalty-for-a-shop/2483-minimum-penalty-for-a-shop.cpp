class Solution {
public:
    int bestClosingTime(string customers) {
        int sum=0;
        for(auto c:customers)
            sum+=c=='N';
        int mn=sum,idx=customers.size();
        for(int i=customers.size()-1;i>=0;i--){
            if(customers[i]=='Y')sum++;
            else sum--;
            if(sum<=mn){
                mn=sum;
                idx=i;
            }
        }
        return idx;
    }
};