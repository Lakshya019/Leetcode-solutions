class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<long long, int> mpp;
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }

        for(auto it : mpp){
            if(it.second == 1){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};