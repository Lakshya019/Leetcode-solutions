class Solution {
public:
    bool isPalindrome(int i, int j,  string &s){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void f(int i, int n, string &s, vector<string> &path, vector<vector<string>> &ans){
        if(i == n){
            ans.push_back(path);
            return;
        }
        for(int j = i; j < n; j++){
            if(isPalindrome(i, j, s)){
                path.push_back(s.substr(i, j - i + 1));

                f(j + 1, n , s, path, ans);

                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> path;
        f(0, n, s, path, ans);

        return ans;
    }
};