//Beats 100.00% of users with C++
class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int matchingCounter=0;
        int index=0;
        return metedTarget(index,matchingCounter,hours,target);
    }
      int  metedTarget(int i,int  counter,vector<int>& hours,int targetPoint){
        if(i==hours.size()){
            return counter;
        }
        if(hours[i]>=targetPoint){
            counter++;
        }
        return  metedTarget(i+1,counter,hours,targetPoint);
      }
};
