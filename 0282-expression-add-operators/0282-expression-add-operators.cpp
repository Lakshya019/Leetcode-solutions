class Solution {
public:
    vector<string> ans;
    void solve(string &num, int target, int ind, string exp, long long value, long long last){
        if(ind == num.size()){
            if(value == target){
                ans.push_back(exp);
            }
            return;
        }
        for(int i = ind; i < num.size(); i++){
            if(i > ind && num[ind] == '0'){
                break;
            }
            string part = num.substr(ind, i - ind + 1);
            long long curr = stoll(part);
            if(ind == 0){
                solve(num, target, i + 1, part, curr, curr);
            }else {
                solve(num, target, i + 1,exp + "+" + part, value + curr, curr);
                
                solve(num, target, i + 1,exp + "-" + part, value - curr, -curr);
                solve(num, target, i + 1,exp + "*" + part, value - last + last * curr,
                last * curr);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        ans.clear();
        solve(num, target, 0, "",0,0);
        return ans;
    }
};