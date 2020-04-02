class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[ nums[i] ]+=1;
        }
        
        int ans=0;
        
        for(auto a : mp)
        {
            if(a.second == 1){
                ans = a.first;   
                break;
            }
        }
        return ans;
    }
};