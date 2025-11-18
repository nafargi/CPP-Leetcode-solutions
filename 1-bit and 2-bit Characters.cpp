public:
    bool isOneBitCharacter(vector<int>& bits) {
        for(int i=0;i<bits.size();)
        {
            if(bits[i]==1)
            {
                i+=2;
                continue;
            }
            else if(bits[i]==0 && i!=bits.size()-1)
            {
                i++;
                continue;
            }
            else 
            {
                return true;
            }
        }
        return false;    
    }
};````
