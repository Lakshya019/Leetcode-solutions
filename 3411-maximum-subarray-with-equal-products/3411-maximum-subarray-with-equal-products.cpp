class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            bool valid = true;
            for(int j = i; j < n; j++) {
                if(j > i) {
                    for(int k = i; k < j; k++) {
                        if(gcd(nums[k], nums[j]) != 1) {
                            valid = false;
                            break;
                        }
                    }
                }
                int len = j - i + 1;
                if(len == 1 && nums[i] == 1)
                    ans = max(ans, len);
                else if(len == 2 || (len >= 3 && valid))
                    ans = max(ans, len);
            }
        }
        return ans;
    }
};