class Solution 
{
public:
    vector<int> constructDistancedSequence(int n) 
    {
        vector<int> result(2 * n - 1, -1); 
        vector<bool> used(n + 1, false); 

        solve(0, n, result, used);

        return result;
    }

private:
    bool solve(int i, int n, vector<int>& result, vector<bool>& used) 
    {
        if (i >= result.size())
        {
            return true;
        } 

        if (result[i] != -1)
        {
            return solve(i + 1, n, result, used);
        } 

        for (int num = n; num >= 1; num--)
        {
            if (used[num])
            {
                continue; 
            } 

            used[num] = true;
            result[i] = num;

            if (num == 1 || (i + num < result.size() && result[i + num] == -1))
            {
                if (num > 1)
                {
                    result[i + num] = num;
                } 

                if (solve(i + 1, n, result, used))
                {
                    return true;
                } 

                if (num > 1)
                {
                    result[i + num] = -1;
                } 
            }

            used[num] = false;
            result[i] = -1;
        }

        return false;
    }
};
