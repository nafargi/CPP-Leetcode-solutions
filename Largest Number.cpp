class Solution {
public:
    string largestNumber(vector<int>& nums) {
    //creating the string vector to hold string of nums
      vector<string> numString;

  //looping in order to put each values in the numString 
      for(int num : nums){
        numString.push_back(to_string(num));
      }

      sort(numString.begin(), numString.end(),[](const string& a, const string& b){
        return (b+a) < (a+b);
      });

      if(numString[0] == "0"){
         return "0";
        }

        string largest;

        for(const string& num: numString){
            largest += num;
        }

     return largest;
    }
};
