class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> altitude(gain.size()+ 1,0);
        int maxAltitude = 0;
        for(int i=1; i<gain.size() +1; i++){
            altitude[i] =altitude[i-1]  + gain[i-1];
            maxAltitude = max(maxAltitude,altitude[i]);
        }
        return maxAltitude;
    }
};
