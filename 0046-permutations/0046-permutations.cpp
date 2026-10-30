class Solution {
public:
    void solve(vector<int> &nums, vector<int> &temp, vector<int> &visited, vector<vector<int>> & ans, int n){
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                visited[i] = 1;
                temp.push_back(nums[i]);
                solve(nums, temp, visited,ans, n);
                temp.pop_back();
                visited[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> visited(n, 0);

        solve(nums, temp, visited, ans, n);
        return ans;
    }
};