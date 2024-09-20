class Solution 
{
public:
    void helper(string &s,string &curr,vector<string>&v,int index,unordered_set<string>&dict)
    {
        if(index==s.length())
        {
            curr.erase(curr.begin()+curr.length()-1);
            v.push_back(curr);
            return;
        }
        string tmp="";
        for(int i=index;i<s.length();i++)
        {
            tmp.push_back(s[i]);
            if(dict.find(tmp)!=dict.end())
            {
                string aux=curr;
                curr+=(tmp+" ");
                helper(s,curr,v,i+1,dict);
                curr=aux;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        
        unordered_set<string>dict(wordDict.begin(),wordDict.end());
        vector<string>v;
        string curr="";
        helper(s,curr,v,0,dict);
        return v;
    }
};
