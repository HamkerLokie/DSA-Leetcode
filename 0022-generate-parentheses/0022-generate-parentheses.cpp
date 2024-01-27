class Solution {
public:
    void solution(int open, int close, string temp, vector<string>& res)
    {
        if(open==0 && close ==0){
            res.push_back(temp);
        }
        if(open > 0){
            temp.push_back('(');
            solution(open-1, close, temp, res);
            temp.pop_back();
        }
        if(open < close){
            temp.push_back(')');
            solution(open, close-1, temp, res);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open = n, close = n;
        string temp;
        
        solution(open, close, temp, ans);
        
        return ans;
        
    }
};