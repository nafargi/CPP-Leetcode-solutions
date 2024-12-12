class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(int i:gifts){
            pq.push(i);
        }
        int tmp;
        while(k-- &&!pq.empty()){
            tmp = pq.top();
            pq.pop();
            pq.push(pow(tmp,0.5));
        }
        long long sum=0;
        while(!pq.empty()){
            sum +=pq.top();
            pq.pop();
        }
        return sum;
    }
};
