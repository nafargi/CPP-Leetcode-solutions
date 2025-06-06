class Solution 
{
public:
    string robotWithString(string s) 
    {
        int n = s.size();

        // Step 1: Initialize min_suffix array
        vector<char> minSuffix(n);
        minSuffix[n - 1] = s[n - 1];

        // Step 2: Fill min_suffix from right to left
        for (int i = n - 2; i >= 0; --i) 
        {
            minSuffix[i] = min(s[i], minSuffix[i + 1]);
        }

        // Step 3: Initialize result and stack
        stack<char> stk;
        string result;
        int i = 0;

        // Step 4: Process characters from s
        while (i < n) 
        {
            stk.push(s[i]); // Push to t
            i++;

            // Step 4 (cont.): Pop from t if top is <= remaining min char
            while (!stk.empty() && (i == n || stk.top() <= minSuffix[i])) 
            {
                result += stk.top();
                stk.pop();
            }
        }

        // Step 5: Clean remaining stack
        while (!stk.empty()) 
        {
            result += stk.top();
            stk.pop();
        }

        // Step 6: Return result
        return result;
    }
};
