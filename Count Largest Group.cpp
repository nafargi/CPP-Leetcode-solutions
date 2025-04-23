class Solution {
public:
    int countLargestGroup(int n) {

        vector<int> sumCount(40, 0);
        for(int i=1;i<=n;i++){
            int currsum = 0, num = i;

            while(num){
                currsum += num % 10;
                num /= 10;
            }

            sumCount[currsum]++;
        }

        int largestSize = *max_element(sumCount.begin(),sumCount.end());

        int numgroups = 0;

        for(auto &i: sumCount){
            if(i==largestSize){
                numgroups++;
            }
        }

        return numgroups;
    }
};
