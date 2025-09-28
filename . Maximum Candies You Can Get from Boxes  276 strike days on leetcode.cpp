class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int ans = 0;
        queue <int> q;
        vector <bool> reachedClosedBoxes(status.size());

        auto pushBoxesIfPossible = [&status,&q , &reachedClosedBoxes](const vector<int> &boxes){
            for (const int box: boxes)
              if(status[box])
               q.push(box);
              else
                reachedClosedBoxes[box] = true;
        };
      pushBoxesIfPossible(initialBoxes);

      while(!q.empty()){
        const int currBox = q.front();
        q.pop();
        ans += candies[currBox];

        for (const int key :keys[currBox]){
            if (!status[key] && reachedClosedBoxes[key])
                q.push(key);
            status[key] = 1;
        }
        pushBoxesIfPossible(containedBoxes[currBox]);

      }

      return ans;
    }
};
