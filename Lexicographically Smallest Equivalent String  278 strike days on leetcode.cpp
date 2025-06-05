class Solution 
{
public:
    int parent[26];
    string smallestEquivalentString(string s1, string s2, string baseStr) 
    {
        // Step 1: Initialize parent array
        for (int i = 0; i < 26; ++i) 
        {
            parent[i] = i;
        }

        // Step 4: Build equivalence groups
        for (int i = 0; i < s1.length(); ++i) 
        {
            unionSets(s1[i] - 'a', s2[i] - 'a');
        }

        // Step 5: Transform baseStr
        string result = "";
        for (char ch : baseStr) 
        {
            result += (char)(find(ch - 'a') + 'a');
        }

        return result;
    }

private:
    // Step 2: Find with path compression
    int find(int x) 
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    // Step 3: Union with lexicographical priority
    void unionSets(int x, int y) 
    {
        int px = find(x), py = find(y);
        if (px == py)
        {
            return;
        }

        if (px < py)
        {
            parent[py] = px;
        }
        else
        {
            parent[px] = py;
        }
    }
};
