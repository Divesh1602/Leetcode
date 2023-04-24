class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto a:stones)
            pq.push(a);
        while(pq.size()>1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            if(x!=y)
                pq.push(x-y);
        }
        if(pq.empty())
            return 0;
        return pq.top();
    }
};