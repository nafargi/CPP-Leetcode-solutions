//this code Beats 94.72% of users with C++
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
      vector<int> decoded(encoded.size()+1);
       decoded[0]=first;

       for(int i=0; i<encoded.size(); i++){
         decoded[i+1]=encoded[i] ^ decoded[i];
       }
       return decoded; 
    }
};
