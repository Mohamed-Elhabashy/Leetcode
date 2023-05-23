class KthLargest {
public:
    priority_queue<int>pq;
    int idx;
    KthLargest(int k, vector<int>& nums) {
        for(auto x:nums)pq.push(-x);
        idx=k;
    }
    
    int add(int val) {
        pq.push(-val);
        while(pq.size()>idx){
            pq.pop();
        }
        return -pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */